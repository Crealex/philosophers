/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:00:57 by alexandre         #+#    #+#             */
/*   Updated: 2024/12/30 16:18:00 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_eat(t_philo **philos)
{
	int i;

	i = 0;
	while (i < philos[i]->id)
	{
		// checker si count_eat est egal ou superieur a many_eat
	}
}

int	check_death(t_philo **philos)
{
	int i;

	i = 0;
	while (i < philos[i]->id)
	{
		// checker si le temps depuis le dernier repas et superieur ou egal a tdie
	}
}

void	*monitor(t_data *data)
{
	int i;

	i = 0;
	while (1)
	{
		if (check_death(data->philos))
			return ;
		if (data->many_eat > -1)
		{
			if (check_eat(data->philos))
				return ;
		}
	}
}

void	*routine(t_philo *philo)
{
	//si pair : prendre fourchette
	//sinon penser
	//apres manger
	//apres dormir
	//garder le controle de la mort
	while (philo->is_dead == 0)
	{
		if (get_time_diff(philo->start) > philo->tdie) // vrm pas sur de l'endroit de cette condititon mais ca donne un exemple de l'utilite de gettimediff
			philo->is_dead = 1;
		//eating();// a continuer
		//sleeping(); a continuer
		//thinking(); p//areille
	}
}

void	create_routine(t_data *data, pthread_t **tid)
{
	int i;
	pthread_t tid_monitor;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_create(tid[i], NULL, routine, &data->philos[i]);
	}
	pthread_create(&tid_monitor, NULL, monitor, data);
}