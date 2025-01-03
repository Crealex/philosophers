/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:22:32 by alexandre         #+#    #+#             */
/*   Updated: 2025/01/03 21:27:56 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	destroy_mutex(t_philo *philo)
{
	pthread_mutex_destroy(&philo->mutex_eat_value);
	pthread_mutex_destroy(&philo->mutex_status_change);
	pthread_mutex_destroy(&philo->right_fork);
	pthread_mutex_destroy(&philo->left_fork);
}

void	finish_sim(t_data *data,t_philo **philos, t_philo *philo, int i)
{
	if (data)
	{
		while (i >= 0)
		{
			destroy_mutex(data->philos[i]);
			i--;
		}
		free_philos(data->philos, i);
		free(data);
	}
	else if (philos)
	{
		while (i >= 0)
		{
			destroy_mutex(philos[i]);
			i--;
		}
		free_philos(philos, i);
	}
	else if (philo)
	{
		destroy_mutex(philo);
		free(philo);
	}
}
