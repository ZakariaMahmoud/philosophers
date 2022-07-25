/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:48:42 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/07/25 12:01:50 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_philo(char *msg, long time, t_philo *philo)
{
	if (pthread_mutex_lock(&t_helper.writing) == 0)
	{
		printf("%ld %d %s\n", time, philo->id + 1, msg);
		pthread_mutex_unlock(&t_helper.writing);
	}
}

void	philo_eating(long time, t_philo *philo)
{
	print_philo("has taken a fork", time, philo);
	print_philo("has taken a fork", time, philo);
	print_philo("is eating", time, philo);
	ft_msleep(t_helper.time_to_eat);
	time = ft_get_diff_time(t_helper.start_time);
	philo->last_meal = time;
}

void	philo_sleeping(long time, t_philo *philo, t_philo *next_philo)
{
	print_philo("is sleeping", time, philo);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&next_philo->fork);
	ft_msleep(t_helper.time_to_sleep);
}

void	*philo_thread(void *arg)
{
	t_philo	*philo;
	t_philo	*next_philo;
	long	time;

	
	philo = (t_philo *) arg;
	next_philo = get_next_philo_by_id(philo->id);
	time = ft_get_diff_time(t_helper.start_time);
	while (time - philo->last_meal < t_helper.time_to_die)
	{
		time = ft_get_diff_time(t_helper.start_time);
		if (pthread_mutex_lock(&philo->fork) == 0 || pthread_mutex_lock(&next_philo->fork) == 0)
		{
			time = ft_get_diff_time(t_helper.start_time);
			if (philo->last_meal != 0)
				print_philo("is thinking", time, philo);
			philo_eating(time, philo);
			time = ft_get_diff_time(t_helper.start_time);
			philo_sleeping(time, philo, next_philo);
			time = ft_get_diff_time(t_helper.start_time);
			
		}
	}
	detach_philos();
	return (0);
}

void	detach_philos()
{
	int		id;
	t_philo	*philos;

	id = 0;
	philos = t_helper.philos;
	while (id < t_helper.number_of_philos)
	{
		pthread_detach(philos[id].thread);
		id++;
	}
}