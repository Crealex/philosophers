/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:19:42 by alexandre         #+#    #+#             */
/*   Updated: 2024/12/30 17:22:51 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/philo.h"

void	eating(t_philo *philo)
{
	print_status(philo, 2);
	usleep(philo->teat * 1000);
	philo->last_eat = get_time_in_miliseconds();
	//reinitialiser le delai de mort
}

void	thinking(t_philo *philo)
{
	print_status(philo, 4);
}
void	sleeping(t_philo *philo)
{
	print_status(philo, 3);
	usleep(philo->tsleep * 1000);
}
void	taking_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->right_fork->mutex_status);
		print_status(philo, 1);
		pthread_mutex_lock(&philo->left_fork->mutex_status);
		print_status(philo, 1);
		eating(philo);
		//gestion des philosophes paires
	}
	else
	{
		usleep(500);
		pthread_mutex_lock(&philo->right_fork->mutex_status);
		print_status(philo, 1);
		pthread_mutex_lock(&philo->left_fork->mutex_status);
		print_status(philo, 1);
		eating(philo);
		//gestion ds philosphes impaires
	}
	// ...
}