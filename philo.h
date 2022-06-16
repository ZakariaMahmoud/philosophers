/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:23:54 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/16 11:52:01 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <limits.h>

typedef struct helper 
{
	int		number_of_philosophers;
	long	time_to_eat;
	long	time_to_sleep;
	long	time_to_die;
	long	times_philo_must_eat;	
}	t_helper;

typedef struct philo
{
	int		id;
	
}	t_philos;

long long	ft_atoi(const char *str);
int			check_args(int argc, char **argv);
int			ft_isdigit(int c);
int			ft_check_args(int argc, char *argv[]);
void		init_helper(int argc, char*argv[], t_helper *helper);

#endif