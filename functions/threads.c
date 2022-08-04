/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:48:42 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/08/04 19:59:20 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_philo(char *msg, t_philo *philo)
{
	long	time;

	if (pthread_mutex_lock(&s_helper.writing) == 0)
	{
		time = ft_get_diff_time(s_helper.start_time);
		printf("%ld %d %s\n", time, philo->id + 1, msg);
		if (msg[0] != 'd')
			pthread_mutex_unlock(&s_helper.writing);
	}
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
			print_philo("has taken a fork 1", philo);
			if (pthread_mutex_lock(&next_philo->fork) == 0)
			{
				print_philo("has taken a fork 2", philo);
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

void	detach_philos(void)
{
	int		id;
	t_philo	*philos;

	id = 0;
	philos = s_helper.philos;
	while (id < s_helper.number_of_philos)
	{
		pthread_detach(philos[id].thread);
		id++;
	}
}
