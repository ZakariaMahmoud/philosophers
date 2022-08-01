/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:48:42 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/08/01 14:34:58 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_philo(char *msg, t_philo *philo)
{
	long	time;

	if (pthread_mutex_lock(&t_helper.writing) == 0)
	{
		time = ft_get_diff_time(t_helper.start_time);
		printf("%ld %d %s\n", time, philo->id + 1, msg);
		pthread_mutex_unlock(&t_helper.writing);
	}
}

void	philo_eating(t_philo *philo, t_philo *next_philo)
{
	print_philo("is eating", philo);
	ft_msleep(t_helper.time_to_eat);
	if (pthread_mutex_unlock(&philo->fork))
		perror("philo->fork unlock");
	if (pthread_mutex_unlock(&next_philo->fork))
		perror("philo->fork unlock");
	philo->last_meal = ft_get_diff_time(t_helper.start_time);
}

void	philo_sleeping(t_philo *philo)
{
	print_philo("is sleeping", philo);
	ft_msleep(t_helper.time_to_sleep);
}

void	philo_thinking(t_philo *philo)
{
	print_philo("is thinking", philo);
}

void	*philo_thread(void *arg)
{
	t_philo	*philo;
	t_philo	*next_philo;

	philo = (t_philo *) arg;
	next_philo = get_next_philo_by_id(philo->id);
	while (1)
	{
		if (pthread_mutex_lock(&philo->fork) == 0)
		{
			print_philo("has taken a fork", philo);
			if (pthread_mutex_lock(&next_philo->fork) == 0)
			{
				print_philo("has taken a fork", philo);
				philo_eating(philo, next_philo);
				philo_sleeping(philo);
				philo_thinking(philo);
			}
			else
				pthread_mutex_unlock(&philo->fork);
		}
	}
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