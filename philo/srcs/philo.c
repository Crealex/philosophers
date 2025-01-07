/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:05:02 by atomasi           #+#    #+#             */
/*   Updated: 2025/01/07 21:11:32 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	join_all_threads(pthread_t *tid, t_data *data)
{
	int i;

	i = 0;
	printf("entree fonction join_all_threads\n");
	printf("nombre de philo : %d\n", data->nb_philo);
	while (i < data->nb_philo)
	{
		printf("tid %d : %ld\n", i, tid[i]);
		printf("rentree dans la boucle while de join all threads\n");
		pthread_join(tid[i], NULL);
		printf("fin de la fonction pthread_join\n");
		i++;
	}
	printf("fin de la fonction join_all_threads\n");
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
			error_usage(1);
		tid = malloc(sizeof(pthread_t) * (data->nb_philo + 1));
		if (!tid)
			return (1);
		gettimeofday(&data->start, NULL);
		philos_init(data);
		printf("test main :\n");
		print_address(data->philos[0]);
		create_routine(data, tid, &tid_monitor);
		printf(RED"\nsortie de create_routine\n"END);
		usleep(500);
		join_all_threads(tid, data);
		finish_sim(data, NULL, NULL, data->nb_philo - 1);
		return (1);
	}
	else
		error_usage(0);
}
