/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:14:37 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/21 14:55:28 by alexandre        ###   ########.fr       */
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

typedef struct s_data
{
	int nb_philo;
	int	tdie;
	int	teat;
	int	tsleep;
	int	many_eat;
	int	id_philo;
}	t_data;

int ft_atoi(const char *str);
t_data *parsing(char **argv);
void	error_usage(int errnum);
void	print_data(t_data *data);


#endif