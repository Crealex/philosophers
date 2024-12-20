/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:05:02 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/19 14:12:53 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		// 1.Parsing
		// 2. La logique (a definir)
	}
	else
	{
		perror(RED"ERROR ! Invalid arguments !\n"END);
		printf("Expected : ./pilo number_of_philosophers time_to_die");
		printf("time_to_eat time_to_sleep");
		printf("(number_of_times_each_philosopher_must_eat)\n");
	}
}