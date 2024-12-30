/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:46:37 by alexandre         #+#    #+#             */
/*   Updated: 2024/12/30 13:56:53 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_time_diff(struct timeval *start)
{
	long long diff_usec;
	struct timeval *now;

	gettimeofday(now, NULL);
	diff_usec = (now->tv_sec - start->tv_sec) * 1000000 +
			(now->tv_usec - start->tv_usec);
	return (diff_usec / 1000);
}

long	get_time_in_miliseconds(void)
{
	struct timeval	*now;
	long			result;

	gettimeofday(now, NULL);
	result = (now->tv_sec * 1000) + (now->tv_usec / 1000);
	return (result);
}

void	ft_usleep(long	msecs)
{
	long	ref;
	long	now;

	ref = get_time_in_miliseconds();
	printf(BLUE"test\n"END);
	while ((now - ref) < msecs)
	{
		printf("diff : %ld\n", now - ref);
		now = get_time_in_miliseconds();
	}
}
