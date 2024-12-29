/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:46:37 by alexandre         #+#    #+#             */
/*   Updated: 2024/12/29 19:52:13 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_time_diff(struct timeval *start)
{
	long long diff_usec;
	struct timeval *now;

	diff_usec = (now->tv_sec - start->tv_sec) * 1000000 +
			(now->tv_usec - start->tv_usec);
	return (diff_usec / 1000);
}