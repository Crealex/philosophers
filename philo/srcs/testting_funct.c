/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testting_funct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:25:31 by alexandre         #+#    #+#             */
/*   Updated: 2025/01/06 21:01:08 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_data(t_data *data)
{
	printf("Il y a %s%d philosophe(s)%s\n", CYAN, data->nb_philo, END);
	printf("Et donc %s%d fourchette(s)%s\n", CYAN, data->nb_philo, END);
	printf("Ils meurent si ils mangent pas toutes les %s%dms%s\n", CYAN, data->tdie, END);
	printf("Il leur faut %s%dms pour manger%s\n", CYAN, data->teat, END);
	printf("Il leur faut %s%dms pour dormir%s\n", CYAN, data->tsleep, END);
	if (data->many_eat > -1)
		printf("Ils doivent manger %s%d fois%s pour finir\n", CYAN, data->many_eat, END);
	else
		printf("Ils doivent manger a %sl'infini%s\n", CYAN, END);
}

void	print_philo_and_fork(t_data *data)
{
	int i;

	i = 0;
	while (i < data->nb_philo)
	{
		print_one_philo(data->philos[i]);
		i++;
	}
}

void	print_one_philo(t_philo *philo)
{
	printf("count_eat : %d\n", philo->count_eat);
	printf("finish_eat : %d\n", philo->finish_eat);
	printf("id :  %d\n", philo->id);
	printf("is_dead : %d\n", *philo->is_dead);
	printf("last_eat : %ld\n", philo->last_eat.tv_sec);
	printf("left_fork : %p\n", &philo->left_fork);
	printf("right_fork : %p\n", &philo->right_fork);
	printf("many_eat : %d\n", philo->many_eat);
	printf("mutex_eat_value : %p\n", &philo->mutex_eat_value);
	printf("mutex_status_change : %p\n", &philo->mutex_status_change);
	printf("nb_philo : %d\n", philo->nb_philo);
	printf("start : %ld\n", philo->start.tv_sec);
	printf("----------------------------------------------\n");
}
