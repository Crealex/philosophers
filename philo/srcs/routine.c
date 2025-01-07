/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:00:57 by alexandre         #+#    #+#             */
/*   Updated: 2025/01/07 21:32:26 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_eat(t_philo **philos) // à tester
{
	int i;

	i = 0;
	if (philos[i]->many_eat == -1)
		return (0);
	while (i + 1 < philos[i]->nb_philo)
	{
		pthread_mutex_lock(&philos[i]->mutex_eat_value);
		if (philos[i]->count_eat >= philos[i]->many_eat)
		{
			pthread_mutex_lock(philos[i]->mutex_status_change);
			philos[i]->finish_eat = 1;
			pthread_mutex_unlock(philos[i]->mutex_status_change);
			return (1);
		}
		pthread_mutex_unlock(&philos[i]->mutex_eat_value);
		i++;
	}
	return (0);
}

int	check_death(t_philo **philos) // à tester
{
	int i;

	i = 0;
	printf("Check death\n");
	while (i  < philos[i]->nb_philo)
	{
		printf("rentre dans la boucle while de check death\n");
		print_one_philo(philos[i]);
		pthread_mutex_lock(&philos[i]->mutex_eat_value);
		if (get_time_diff(&philos[i]->last_eat) >= philos[i]->tdie) // !!!segfault ici!!! (sinon dans ce coin)
		{
			pthread_mutex_unlock(&philos[i]->mutex_eat_value);
			pthread_mutex_lock(philos[i]->mutex_status_change);
			*philos[i]->is_dead = 1;
			pthread_mutex_unlock(philos[i]->mutex_status_change);
			print_status(philos[i], 0);
			return (1);
		}
		printf("Milieu de la boucle\n");
		pthread_mutex_unlock(&philos[i]->mutex_eat_value);
		i++;
		printf("fin de la boucle check death\n");
	}
	return (0);
}

void	*monitor(void *data_void) // à tester
{
	t_philo **philos;

	philos = (t_philo **)data_void;
	printf(BLUE"test\n"END);
	while (1)
	{
		if (check_death(philos))
			return (NULL);
		if (philos[0]->many_eat > -1)
		{
			if (check_eat(philos))
				return (NULL);
		}
		usleep(500);
	}
}

void	*routine(void *data_void) // à tester
{
	t_philo	*philo;
	printf("depuis routine : \n\n");
	philo = (t_philo *)data_void;
	printf("nb philo depus routine : %d", philo->nb_philo);
	printf("Routine : philo %d initialise\n", philo->id);
	printf("Mutex status change : %p\n", (void*)philo->mutex_status_change);
	printf("is_dead pointer : %p\n", (void*)philo->is_dead);
	printf("pointer finsih_eat : %d\n", philo->finish_eat);
	//print_address(philo);
	//print_one_philo(philo);
	if (!philo || !philo->mutex_status_change || !philo->is_dead)
	{
		printf("Erreur: pointeur invalide pour philo %d\n", philo ? philo->id : -1);
		return( NULL);
    }
	printf("tentative de verrouillage du mutex pour le philo : %d\n", philo->id);
	pthread_mutex_lock(philo->mutex_status_change);
	printf("mutex verouille pour le philo : %d\n", philo->id);
	while (*philo->is_dead == 0 && philo->finish_eat == 0)
	{
		printf(BOLD"rentree dans la boucle while\n"END);
		pthread_mutex_unlock(philo->mutex_status_change);
		thinking(philo);
		taking_fork(philo);
		sleeping(philo);
		pthread_mutex_lock(philo->mutex_status_change);
	}
	printf(BOLD CYAN"fin boucle routine\n"END);
	pthread_mutex_unlock(philo->mutex_status_change);
	return (NULL);
}

void	create_routine(t_data *data, pthread_t *tid, pthread_t *tid_monitor) // à tester
{
	int i;

	i = 0;
	if (pthread_create(tid_monitor, NULL, monitor, data->philos) == -1)
		return ;
	while (i < data->nb_philo)
	{
		printf("depuis create routine : \n\n");
		//print_address(data->philos[i]);
		printf("Tentative de creation du thread pour le philo %d\n", i + 1);
		if (pthread_create(&tid[i], NULL, routine, data->philos[i]) == -1) // qqch se passe entre le tid et la routine, des choses differentes se passe en relancant le pgramme plusieurs fois!
		{
			printf("Erreur creation du thread %d\n", i);
			return ;
		}
		printf(RED"tid %d dans create_routine : %ld\nEND", i, tid[i]);
		i++;
	}
	printf("fini la boucle dans create_routine\n");
	printf("fin de la fonction create_routine\n");
}
