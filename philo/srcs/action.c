/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:19:42 by alexandre         #+#    #+#             */
/*   Updated: 2024/12/31 10:44:57 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/philo.h"

void	eating(t_philo *philo) // à tester
{
	print_status(philo, 2);
	ft_usleep(philo->teat);
	gettimeofday(philo->last_eat, NULL);
}

void	taking_fork(t_philo *philo) // à finir / modifier
{
	if (philo->id % 2 == 0)
		ft_usleep(5);
	pthread_mutex_lock(&philo->right_fork->mutex_status);
	print_status(philo, 1);
	pthread_mutex_unlock(&philo->right_fork->mutex_status);
	pthread_mutex_lock(&philo->left_fork->mutex_status);
	print_status(philo, 1);
	pthread_mutex_unlock(&philo->left_fork->mutex_status);
	eating(philo);
	// ...
}

void	thinking(t_philo *philo)
{
	print_status(philo, 4);
}

void	sleeping(t_philo *philo) // à tester
{
	print_status(philo, 3);
	ft_usleep(philo->tsleep);
}
