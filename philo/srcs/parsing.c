/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:13:49 by alexandre         #+#    #+#             */
/*   Updated: 2024/12/20 18:08:36 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
	data->id_philo = 0;
	return (data);
}
