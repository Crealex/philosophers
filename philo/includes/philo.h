/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomasi <atomasi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:14:37 by atomasi           #+#    #+#             */
/*   Updated: 2025/01/06 16:49:34 by atomasi          ###   ########.fr       */
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

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				count_eat;
	struct timeval	last_eat;
	int				*is_dead; //variable partagee par tout les philos.
	int				finish_eat;
	pthread_mutex_t	*mutex_status_change;
	pthread_mutex_t	mutex_eat_value;
	int				tdie;
	int				teat;
	int				tsleep;
	int				many_eat;
	int				nb_philo;
	struct timeval	start;
}	t_philo;

typedef struct s_data
{
	int nb_philo;
	int	tdie;
	int	teat;
	int	tsleep;
	int	many_eat;
	struct timeval start;
	t_philo	**philos;
}	t_data;

int ft_atoi(const char *str);
t_data *parsing(char **argv);
int	philos_init(t_data *data);
void	error_usage(int errnum);
void	print_status(t_philo *philo, int status);
void	free_philos(t_philo **philos, int i);
//action.c
void	eating(t_philo *philo);
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);
void	taking_fork(t_philo *philo);
//time_manager
long long	get_time_diff(struct timeval *start);
long long	get_time_in_miliseconds();
void	ft_usleep(long long	msecs);
// testing
void	print_data(t_data *data);
void	print_philo_and_fork(t_data *data);
void	print_one_philo(t_philo *philo);
//routine.c
void	create_routine(t_data *data, pthread_t **tid);
//exit.c
void	finish_sim(t_data *data,t_philo **philos, t_philo *philo, int i);



#endif