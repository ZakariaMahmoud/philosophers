/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:24:05 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/08/06 13:10:14 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_philo_died(t_philo *philo)
{
	long		time;

	time = ft_get_diff_time(s_helper.start_time);
	if (pthread_mutex_lock(&philo->m_last_meal) == 0)
	{
		if (time - philo->last_meal >= s_helper.time_to_die)
		{
			print_philo("died", philo);
			pthread_mutex_unlock(&philo->m_last_meal);
			return (1);
		}
		pthread_mutex_unlock(&philo->m_last_meal);
	}
	return (0);
}

int	check_must_eat(void)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < s_helper.number_of_philos)
	{
		philo = get_philo_by_id(i++);
		if (pthread_mutex_lock(&philo->m_must_eat) == 0)
		{
			if (philo->must_eat < s_helper.times_philo_must_eat)
			{
				pthread_mutex_unlock(&philo->m_must_eat);
				return (0);
			}
			pthread_mutex_unlock(&philo->m_must_eat);
		}
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_philo		*philo;
	int			i;

	i = 0;
	if ((argc == 5 || argc == 6)
		&& ft_check_args(argc, argv) && init_helper(argc, argv))
	{
		create_philos();
		while (1)
		{
			philo = get_philo_by_id(i++);
			if (i == s_helper.number_of_philos)
				i = 0;
			if (check_if_philo_died(philo))
				break ;
			if (s_helper.times_philo_must_eat != -1 && check_must_eat())
				break ;
		}
	}
}
