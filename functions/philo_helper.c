/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:28:56 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/08/06 23:39:20 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	*get_philo_by_id(int id)
{
	if (id < s_helper.number_of_philos)
		return (&s_helper.philos[id]);
	return (0);
}

t_philo	*get_next_philo_by_id(int id)
{
	if (id + 1 < s_helper.number_of_philos)
		return (&s_helper.philos[id + 1]);
	else if (id + 1 == s_helper.number_of_philos)
		return (&s_helper.philos[0]);
	return (0);
}

void	philo_eating(t_philo *philo, t_philo *next_philo)
{
	print_philo("is eating", philo);
	pthread_mutex_lock(&philo->m_last_meal);
	philo->last_meal = ft_get_diff_time(s_helper.start_time);
	pthread_mutex_unlock(&philo->m_last_meal);
	pthread_mutex_lock(&philo->m_must_eat);
	philo->must_eat++;
	pthread_mutex_unlock(&philo->m_must_eat);
	ft_msleep(s_helper.time_to_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&next_philo->fork);
}

void	philo_sleeping(t_philo *philo)
{
	print_philo("is sleeping", philo);
	ft_msleep(s_helper.time_to_sleep);
}

void	philo_thinking(t_philo *philo)
{
	print_philo("is thinking", philo);
}
