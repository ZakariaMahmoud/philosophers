/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:23:54 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/07/03 12:41:21 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct philo
{
	int				id;
	long			time_died;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t fork;
	struct helper		*helper;
}	t_philo;

typedef struct helper 
{
	int				number_of_philos;
	long			time_to_eat;
	long			time_to_sleep;
	long			time_to_die;
	long			times_philo_must_eat;
	long			start_time;
	pthread_mutex_t	writing;
	t_philo 		*philos;
}	t_helper;

long long	ft_atoi(const char *str);
long 		ft_get_time();
long 		ft_get_diff_time(long diff);
int			check_args(int argc, char **argv);
int			ft_isdigit(int c);
int			ft_check_args(int argc, char *argv[]);
void		init_helper(int argc, char*argv[], t_helper *helper);
void		init_philos(t_helper *helper);
void		ft_msleep(int milliseconds);
t_philo		*get_philo_by_id(t_helper *helper, int id);
t_philo		*get_next_philo(t_helper *helper, int id);

#endif