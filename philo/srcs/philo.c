/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:05:02 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/23 10:47:19 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//a mettre peut etre dans le fichier parsing
int	philos_init(t_data *data)
{
	int i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philos[i] = malloc(sizeof(t_philo) * 1);
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
	data->philos[0]->left_fork = data->philos[data->nb_philo - 1]->right_fork;
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
		philos_init(data);
		print_data(data);
		//print_status(data, 0, 0);
		print_philo_and_fork(data);
		// 2. La logique (a definir)
	}
	else
		error_usage(0);
}