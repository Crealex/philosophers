/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:14:37 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/30 10:18:34 by atomasi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

// COLOR
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define BOLD "\033[1m"
# define END "\033[0m"

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	mutex_status;
}	t_fork;

typedef struct s_philo
{
	int				id;
	t_fork			*left_fork;
	t_fork			*right_fork;
	int				count_eat;
	double			last_eat;
	int				is_dead;
	pthread_mutex_t mutex_dead;
	int				tdie;
	int				teat;
	int				tsleep;
	int				many_eat;
	struct timeval	*start;
}	t_philo;

typedef struct s_data
{
	int nb_philo;
	int	tdie;
	int	teat;
	int	tsleep;
	int	many_eat;
	struct timeval *start;
	t_philo	**philos;
}	t_data;

int ft_atoi(const char *str);
t_data *parsing(char **argv);
int	philos_init(t_data *data);
void	error_usage(int errnum);
void	print_status(t_philo *philo, int status);
void	free_philos(t_data *data, int i);
//time_manager
long	get_time_diff(struct timeval *start);
long	get_time_in_miliseconds();
void	ft_usleep(long	msecs);
// testing
void	print_data(t_data *data);
void	print_philo_and_fork(t_data *data);



#endif