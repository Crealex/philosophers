/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:05:02 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/30 18:01:20 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int argc, char **argv) // à tester / finir / modifier pour opti
{
	if (argc == 5 || argc == 6)
	{
		t_data *data;
		pthread_t *tid;
		// 1.Parsing

		data = parsing(argv);
		tid = malloc(sizeof(pthread_t) * data->nb_philo);
		if (!tid)
			return (1);
		if (!data)
			error_usage(1);
		// recuperatino du temps du debut
		gettimeofday(data->start, NULL);
		//2. Init les philos et forks
		philos_init(data);
		print_data(data);
		//print_status(data, 0, 0);
		print_philo_and_fork(data);
		// 2. La logique (a definir)
		//	2.1 Creer une routine pour chaque philo (avec les threads)
		create_routine(data, &tid);
		//	2.2 Faire depuis routine, des fonction eat, sleep et think
		//	2.3 faire une thread de monitoring
		// !! pas oublier le monitoring de faim (timestamp) et de mort (avec un thread dediee)
		// et mettre ajour la varibale partagee is_dead;
	}
	else
		error_usage(0);
}
