/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:19:42 by alexandre         #+#    #+#             */
/*   Updated: 2025/01/03 21:09:26 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/philo.h"

void	eating(t_philo *philo) // à tester
{
	print_status(philo, 2);
	ft_usleep(philo->teat);
	pthread_mutex_lock(&philo->mutex_eat_value);
	if (gettimeofday(philo->last_eat, NULL) == -1)
	{
		pthread_mutex_unlock(&philo->mutex_eat_value);
		return ;
	}
	philo->count_eat++;
	pthread_mutex_unlock(&philo->mutex_eat_value);
}

void	taking_fork(t_philo *philo) // à finir / modifier
{
	if (philo->id % 2 == 0)
		ft_usleep(5);
	pthread_mutex_lock(&philo->right_fork);
	print_status(philo, 1);
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_lock(&philo->left_fork);
	print_status(philo, 1);
	pthread_mutex_unlock(&philo->left_fork);
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
