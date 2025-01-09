/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:46:37 by alexandre         #+#    #+#             */
/*   Updated: 2025/01/09 14:14:39 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	get_time_diff(struct timeval *start)
{
	long long diff_usec;
	struct timeval now;
	gettimeofday(&now, NULL);
	diff_usec = (now.tv_sec - start->tv_sec) * 1000000 +
			(now.tv_usec - start->tv_usec);
	return (diff_usec / 1000);
}

long long	get_time_in_miliseconds(void)
{
	struct timeval	now;
	long long		result;

	gettimeofday(&now, NULL);
	result = (now.tv_sec * 1000) + (now.tv_usec / 1000);
	return (result);
}

void	ft_usleep(long long	msecs)
{
	long long	ref;
	long long	now;

	ref = get_time_in_miliseconds();
	now = ref;
	while ((now - ref) < msecs)
	{
		usleep(50);
		now = get_time_in_miliseconds();
	}
}
