/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:23:54 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/08/05 01:25:53 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct philo
{
	int				id;
	int				must_eat;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t	m_last_meal;
	pthread_mutex_t	m_must_eat;
	pthread_mutex_t	fork;
}	t_philo;

struct s_helper
{
	int				number_of_philos;
	long			time_to_eat;
	long			time_to_sleep;
	long			time_to_die;
	long			times_philo_must_eat;
	long			start_time;
	t_philo			*philos;
	pthread_mutex_t	writing;

}	s_helper;

int			init_helper(int argc, char*argv[]);
int			ft_isdigit(int c);
int			ft_check_args(int argc, char *argv[]);
long		ft_get_diff_time(long diff);
long		ft_get_time(void);
void		init_philos(void);
void		create_even_philos(void);
void		create_odd_philos(void);
void		create_philos(void);
void		detach_philos(void);
void		*philo_thread(void	*args);
void		ft_msleep(long milliseconds);
void		print_philo(char *msg, t_philo *philo);
void		philo_eating(t_philo *philo, t_philo *next_philo);
void		philo_sleeping(t_philo *philo);
void		philo_thinking(t_philo *philo);
long long	ft_atoi(const char *str);
t_philo		*get_philo_by_id(int id);
t_philo		*get_next_philo_by_id(int id);

#endif