/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:00:57 by alexandre         #+#    #+#             */
/*   Updated: 2025/01/08 17:15:40 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_eat(t_philo **philos) // à tester
{
	int i;

	i = 0;
	if (philos[i]->many_eat == -1)
		return (0);
	while (i < philos[0]->nb_philo)
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
	while (i < philos[0]->nb_philo)
	{
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
		pthread_mutex_unlock(&philos[i]->mutex_eat_value);
		i++;
	}
	return (0);
}

void	*monitor(void *data_void) // à tester
{
	t_philo **philos;

	philos = (t_philo **)data_void;
	while (1)
	{
		if (check_death(philos))
			return (NULL);
		if (philos[0]->many_eat > -1)
		{
			if (check_eat(philos))
				return (NULL);
		}
		usleep(50);
	}
}

void	*routine(void *data_void)
{
	t_philo	*philo;
	philo = (t_philo *)data_void;
	if (!philo || !philo->mutex_status_change || !philo->is_dead)
		return (printf("Erreur: pointeur invalide pour un  philo\n"), NULL);
	pthread_mutex_lock(philo->mutex_status_change);
	while (*philo->is_dead == 0 && philo->finish_eat == 0)
	{
		pthread_mutex_unlock(philo->mutex_status_change);
		pthread_mutex_lock(philo->mutex_status_change);
		if (*philo->is_dead == 0 && philo->finish_eat == 0)
			thinking(philo);
		pthread_mutex_unlock(philo->mutex_status_change);
		pthread_mutex_lock(philo->mutex_status_change);
		if (*philo->is_dead == 0 && philo->finish_eat == 0)
			taking_fork(philo);
		pthread_mutex_unlock(philo->mutex_status_change);
		pthread_mutex_lock(philo->mutex_status_change);
		if (*philo->is_dead == 0 && philo->finish_eat == 0)
			sleeping(philo);
		pthread_mutex_unlock(philo->mutex_status_change);
		pthread_mutex_lock(philo->mutex_status_change);
	}
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
		if (pthread_create(&tid[i], NULL, routine, data->philos[i]) == -1)
		{
			printf("Erreur creation du thread %d\n", i);
			return ;
		}
		i++;
	}
}
