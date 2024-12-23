/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:05:02 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/23 16:50:25 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//a mettre peut etre dans le fichier parsing
int	philos_init(t_data *data)
{
	int i;

	i = 0;
	data->philos = malloc(sizeof(t_philo *) * 1);
	while (i < data->nb_philo)
	{
		data->philos[i] = malloc(sizeof(t_philo) * 1);
		if (i == 0)
			pthread_mutex_init(&data->philos[0]->is_dead, NULL);
		else
			data->philos[i]->is_dead = data->philos[0]->is_dead;
		if (!data->philos[i])
			return (free_philos(data, i), 0);
		data->philos[i]->right_fork = malloc(sizeof(t_fork) * 1);
		if (!data->philos[i]->right_fork)
			return (free_philos(data, i), 0);
		data->philos[i]->id = i + 1;
		data->philos[i]->right_fork->id = i + 1;
		pthread_mutex_init(&data->philos[i]->right_fork->mutex_status, NULL);
		if (i > 0)
			data->philos[i]->left_fork = data->philos[i - 1]->right_fork;
		i++;
	}
	data->philos[0]->left_fork = data->philos[i - 1]->right_fork;
	return (1);
}

int main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		t_data *data;
		// 1.Parsing

		data = parsing(argv);
		if (!data)
			error_usage(1);
		//2. Init les philos et forks
		philos_init(data);
		print_data(data);
		//print_status(data, 0, 0);
		print_philo_and_fork(data);
		// 2. La logique (a definir)
		//	2.1 Creer une routine pour chaque philo (avec les threads)
		//	2.2 Fare depuis routine, des fonction eat, sleep et think
		//	2.3 faire une thread de monitoring
		// !! pas oublier le monitoring de faim (timestamp) et de mort (avec un thread dediee)
		// et mettre ajour la varibale partagee is_dead;
	}
	else
		error_usage(0);
}