/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:21:20 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/31 10:38:15 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	malus;
	int	res;

	i = 0;
	malus = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			malus = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * malus);
}

void	error_usage(int errnum)
{
	if (errnum == 0)
		write(2, RED"ERROR ! Only 4 or 5 arguments are accepted !\n"END, 57);
	else if (errnum == 1)
		write(2, RED"ERROR ! Only positives numbers are accepted !\n"END, 58);
	printf("%sExpected : %s./philo number_of_philosophers time_to_die ", BOLD, END);
	printf("time_to_eat time_to_sleep ");
	printf("[number_of_times_each_philosopher_must_eat]\n");
	exit(EXIT_FAILURE);
}
// 0 = die
// 1 = fork
// 2 = eating
// 3 = sleeping
// 4 = thinking
void	print_status(t_philo *philo, int status)
{
	long long time_ms;

	time_ms = get_time_in_miliseconds();
	if (status == 0)
	{
		printf(RED"%lld %d died\n"END, time_ms, philo->id);
		return ;
	}
	if (status == 1)
		printf("%lld %d has taken a fork\n", time_ms, philo->id);
	else if (status == 2)
		printf("%lld %d is eating\n", time_ms, philo->id);
	else if (status == 3)
		printf("%lld %d is sleeping\n", time_ms, philo->id);
	else if (status == 4)
		printf("%lld %d is thinking\n", time_ms, philo->id);
}

void	free_philos(t_data *data, int i) // à tester
{
	while (i >= 0)
	{
		if (data->philos[i]->right_fork)
			free(data->philos[i]->right_fork);
		if (data->philos[i])
			free(data->philos[i]);
		i--;
	}
	if (data->philos)
		free(data->philos);
}