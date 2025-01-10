/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:05:02 by atomasi           #+#    #+#             */
/*   Updated: 2025/01/10 10:38:11 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	join_all_threads(pthread_t *tid,pthread_t monitoring, t_data *data)
{
	int i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	pthread_join(monitoring, NULL);
}

int	 main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		t_data *data;
		pthread_t *tid;
		pthread_t tid_monitor;

		data = parsing(argv);
		if (!data)
		{
			error_usage(1);
			return (1);
		}
		tid = malloc(sizeof(pthread_t) * (data->nb_philo + 1));
		if (!tid)
			return (1);
		gettimeofday(&data->start, NULL);
		philos_init(data);
		create_routine(data, tid, &tid_monitor);
		join_all_threads(tid, tid_monitor, data);
		finish_sim(data, NULL, NULL, data->nb_philo - 1);
		return (0);
	}
	else
		error_usage(0);
}
