/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:24:05 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/08/11 02:39:30 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_philo_died(t_philo *philo)
{
	long		time;

	time = ft_get_diff_time(philo->helper->start_time);
	if (pthread_mutex_lock(&philo->m_last_meal) == 0)
	{
		if (time - philo->last_meal >= philo->helper->time_to_die)
		{
			print_philo("died", philo);
			pthread_mutex_unlock(&philo->m_last_meal);
			return (1);
		}
		pthread_mutex_unlock(&philo->m_last_meal);
	}
	return (0);
}

int	check_must_eat(t_helper *helper)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < helper->number_of_philos)
	{
		philo = get_philo_by_id(i++, helper);
		if (pthread_mutex_lock(&philo->m_must_eat) == 0)
		{
			if (philo->must_eat < helper->times_philo_must_eat)
			{
				pthread_mutex_unlock(&philo->m_must_eat);
				return (0);
			}
			pthread_mutex_unlock(&philo->m_must_eat);
		}
	}
	pthread_mutex_lock(&helper->writing);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_philo		*philo;
	t_helper	helper;
	int			i;

	i = 0;
	if ((argc == 5 || argc == 6)
		&& ft_check_args(argc, argv) && init_helper(argc, argv, &helper))
	{
		create_philos(&helper);
		while (1)
		{
			usleep(10);
			philo = get_philo_by_id(i++, &helper);
			if (i == helper.number_of_philos)
				i = 0;
			if (check_if_philo_died(philo))
				break ;
			if (helper.times_philo_must_eat != -1 && check_must_eat(&helper))
				break ;
		}
	}
	return (0);
}
