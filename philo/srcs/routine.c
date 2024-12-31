/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:00:57 by alexandre         #+#    #+#             */
/*   Updated: 2024/12/31 10:56:28 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_eat(t_philo **philos) // à tester
{
	int i;

	i = 0;
	while (i < philos[i]->id)
	{
		if (philos[i]->count_eat >= philos[i]->many_eat)
		{
			philos[i]->finish_eat = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_death(t_philo **philos) // à tester
{
	int i;

	i = 0;
	while (i < philos[i]->id)
	{
		if (get_time_diff(philos[i]->last_eat) >= philos[i]->tdie)
		{
			philos[i]->is_dead = 1;
			print_status(philos[i], 0);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*monitor(void *data_void) // à tester
{
	t_data *data;

	data = (t_data *)data_void;
	while (1)
	{
		if (check_death(data->philos))
			return (NULL);
		if (data->many_eat > -1)
		{
			if (check_eat(data->philos))
				return (NULL);
		}
	}
}

void	*routine(void *data_void) // à tester
{
	t_philo	*philo;

	philo = (t_philo *)data_void;
	while (philo->is_dead == 0 && philo->finish_eat == 0)
	{
		thinking(philo);
		taking_fork(philo);
		sleeping(philo);
	}
	return (NULL);
}

void	create_routine(t_data *data, pthread_t **tid) // à tester
{
	int i;
	pthread_t tid_monitor;

	i = 0;
	pthread_create(&tid_monitor, NULL, monitor, data);
	while (i < data->nb_philo)
	{
		pthread_create(tid[i], NULL, routine, &data->philos[i]);
	}
}
