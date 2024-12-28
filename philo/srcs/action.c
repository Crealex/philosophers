/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:00:05 by alexandre         #+#    #+#             */
/*   Updated: 2024/12/28 22:05:53 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eating(t_philo *philo)
{
	print_status(philo, 2);
	usleep(philo->teat * 1000);
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

void	taking_fork(t_philo)
{

}