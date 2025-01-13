/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:19:42 by alexandre         #+#    #+#             */
/*   Updated: 2025/01/13 16:15:37 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/philo.h"

void	eating(t_philo *philo)
{
	print_status(philo, 2);
	ft_usleep(philo->teat);
	pthread_mutex_lock(&philo->mutex_eat_value);
	if (gettimeofday(&philo->last_eat, NULL) == -1)
	{
		pthread_mutex_unlock(&philo->mutex_eat_value);
		return ;
	}
	philo->count_eat++;
	pthread_mutex_unlock(&philo->mutex_eat_value);
}

void	taking_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_usleep(philo->teat / 3);
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, 1);
	if (philo->nb_philo == 1)
	{
		pthread_mutex_unlock(philo->right_fork);
		ft_usleep(philo->tdie + 1);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, 1);
	eating(philo);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	thinking(t_philo *philo)
{
	print_status(philo, 4);
}

void	sleeping(t_philo *philo)
{
	print_status(philo, 3);
	ft_usleep(philo->tsleep);
}
