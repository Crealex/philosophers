/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_and_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:13:49 by alexandre         #+#    #+#             */
/*   Updated: 2025/01/02 20:37:42 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	cp_utils_data_in_philos(t_data *data, t_philo *philo)
{
	philo->many_eat = data->many_eat;
	philo->tdie = data->tdie;
	philo->teat = data->teat;
	philo->tsleep = data->tsleep;
	philo->start = data->start;
	philo->nb_philo = data->nb_philo;
}

int	philos_init(t_data *data)
{
	int i;

	i = 0;
	data->philos = malloc(sizeof(t_philo *) * data->nb_philo);
	while (i < data->nb_philo)
	{
		data->philos[i] = malloc(sizeof(t_philo) * 1);
		if (!data->philos[i])
			return (free_philos(data, i), 0);
		if (i == 0)
			pthread_mutex_init(&data->philos[0]->mutex_dead, NULL);
		else
			data->philos[i]->is_dead = data->philos[0]->is_dead;
		data->philos[i]->right_fork = malloc(sizeof(t_fork) * 1);
		if (!data->philos[i]->right_fork)
			return (free_philos(data, i), 0);
		cp_utils_data_in_philos(data, data->philos[i]);
		data->philos[i]->id = i + 1;
		data->philos[i]->right_fork->id = i + 1;
		pthread_mutex_init(&data->philos[i]->right_fork->mutex_status, NULL);
		if (i > 0)
			data->philos[i]->left_fork = data->philos[i - 1]->right_fork;
		i++;
	}
	return (data->philos[0]->left_fork = data->philos[i - 1]->right_fork, 1);
}

int is_digit(char *res)
{
	int i;

	i = 0;
	while (res[i])
	{
		if (res[i] > '9' || res[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

t_data *parsing(char **argv)
{
	int i;
	t_data *data;

	i = 1;
	data = malloc(sizeof(t_data) * 1);
	while (argv[i])
	{
		if (!is_digit(argv[i]))
			return (NULL);
		i++;
	}
	data->nb_philo = ft_atoi(argv[1]);
	data->tdie = ft_atoi(argv[2]);
	data->teat = ft_atoi(argv[3]);
	data->tsleep = ft_atoi(argv[4]);
	if (argv[5])
		data->many_eat = ft_atoi(argv[5]);
	else
		data->many_eat = -1; // a voir
	return (data);
}
