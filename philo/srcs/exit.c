/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:22:32 by alexandre         #+#    #+#             */
/*   Updated: 2025/01/13 11:48:11 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	destroy_mutex(t_philo *philo)
{
	pthread_mutex_destroy(&philo->mutex_eat_value);
	pthread_mutex_destroy(philo->mutex_status_change);
	pthread_mutex_destroy(philo->right_fork);
}

void	finish_sim(t_data *data,t_philo **philos, t_philo *philo, int i)
{
	if (data)
	{
		destroy_mutex(data->philos[i]);
		free_philos(data->philos, i);
		free(data);
	}
	else if (philos)
	{
		destroy_mutex(philos[i]);
		free_philos(philos, i);
	}
	else if (philo)
	{
		destroy_mutex(philo);
		free(philo);
	}
}
