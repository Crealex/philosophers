/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testting_funct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:25:31 by alexandre         #+#    #+#             */
/*   Updated: 2024/12/21 21:26:29 by alexandre        ###   ########.fr       */
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
