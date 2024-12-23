/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:00:57 by alexandre         #+#    #+#             */
/*   Updated: 2024/12/23 22:28:05 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(t_philo *philo)
{
	//si pair : prendre fourchette
	//sinon penser
	//apres manger
	//apres dormir
	//garder le controle de la mort
	while (philo->is_dead == 0)
	{
		//eating();// a continuer
		//thinking(); p//areille
	}
}

void	create_routine(t_data *data, pthread_t **tid)
{
	int i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_create(tid[i], NULL, routine, &data->philos[i]);
	}
}