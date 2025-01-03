/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:05:02 by atomasi           #+#    #+#             */
/*   Updated: 2025/01/03 14:26:57 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	 main(int argc, char **argv) // à tester / finir / modifier pour opti
{
	if (argc == 5 || argc == 6)
	{
		t_data *data;
		pthread_t *tid;

		data = parsing(argv);
		if (!data)
			error_usage(1);
		tid = malloc(sizeof(pthread_t) * data->nb_philo);
		if (!tid)
			return (1);
		gettimeofday(data->start, NULL);
		philos_init(data);
		create_routine(data, &tid);
		join_all_thread(&tid);
	}
	else
		error_usage(0);
}
