/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:23:54 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/19 11:44:43 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <pthread.h>

typedef struct philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t fork;
}	t_philo;

typedef struct helper 
{
	int		number_of_philos;
	long	time_to_eat;
	long	time_to_sleep;
	long	time_to_die;
	long	times_philo_must_eat;
	t_philo *philos;
		
}	t_helper;

typedef struct groupe 
{
	t_philo		philo;
	t_helper	helper;
}	t_groupe;

long long	ft_atoi(const char *str);
int			check_args(int argc, char **argv);
int			ft_isdigit(int c);
int			ft_check_args(int argc, char *argv[]);
void		init_helper(int argc, char*argv[], t_groupe *t_groupe);
void		init_philos(t_groupe *t_groupe);
t_philo		*get_philo_by_id(t_groupe *t_groupe, int id);
#endif