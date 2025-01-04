/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:05:02 by atomasi           #+#    #+#             */
/*   Updated: 2025/01/04 18:27:31 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	join_all_threads(pthread_t *tid, t_data *data)
{
	int i;

	i = 0;
	while (i < (data->nb_philo + 1))
	{
		pthread_join(tid[i], NULL);
		i++;
	}
}

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
		gettimeofday(&data->start, NULL);
		philos_init(data);
		create_routine(data, &tid);
		join_all_threads(tid, data);
		finish_sim(data, NULL, NULL, data->nb_philo);
		return (1);
	}
	else
		error_usage(0);
}
