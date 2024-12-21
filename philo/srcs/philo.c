/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:05:02 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/21 14:55:41 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		t_data *data;
		// 1.Parsing
		data = parsing(argv);
		if (!data)
			error_usage(1);
		print_data(data);
		// 2. La logique (a definir)
	}
	else
		error_usage(0);
}