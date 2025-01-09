/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_and_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:13:49 by alexandre         #+#    #+#             */
/*   Updated: 2025/01/08 09:54:06 by atomasi          ###   ########.fr       */
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

void	init_shared_variables_and_mutex(t_philo **philos, int i)
{
	if (i == 0)
	{
		philos[i]->mutex_status_change = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philos[0]->mutex_status_change, NULL);
		philos[0]->is_dead = malloc(sizeof(int));
		*philos[0]->is_dead = 0;
	}
	else
	{
		philos[i]->mutex_status_change = philos[0]->mutex_status_change;
		philos[i]->is_dead = philos[0]->is_dead;
	}
	philos[i]->count_eat = 0;
	philos[i]->finish_eat = 0;
	pthread_mutex_init(&philos[i]->mutex_eat_value, NULL);
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
			return (free_philos(data->philos, i), 0);
		init_shared_variables_and_mutex(data->philos, i); // init touts les mutex ici.
		cp_utils_data_in_philos(data, data->philos[i]);
		gettimeofday(&data->philos[i]->last_eat, NULL);
		data->philos[i]->id = i + 1;
		data->philos[i]->right_fork = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(data->philos[i]->right_fork, NULL);
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

t_data *parsing(char **argv) // peut-etre tout mettre direct dans philos ?
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
		data->many_eat = -1;
	return (data);
}
