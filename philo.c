/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:24:05 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/08/04 19:51:28 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_must_eat(void)
{
	t_philo		*philo;
	int			i;

	i = 0;
	while (i < s_helper.number_of_philos)
	{
		philo = get_philo_by_id(i++);
		if (philo->must_eat < s_helper.times_philo_must_eat)
			return (0);
	}
	return (1);
}

void	check_if_philo_died(void)
{
	t_philo		*philo;
	long		time;
	int			i;

	i = 0;
	while (1)
	{
		philo = get_philo_by_id(i++);
		time = ft_get_diff_time(s_helper.start_time);
		if (i == s_helper.number_of_philos)
			i = 0;
		if (pthread_mutex_lock(&philo->m_last_meal) == 0)
		{
			if (time - philo->last_meal > s_helper.time_to_die
				|| (s_helper.times_philo_must_eat != -1 && check_must_eat()))
				break ;
			pthread_mutex_unlock(&philo->m_last_meal);
		}
	}
	if (time - philo->last_meal > s_helper.time_to_die)
		print_philo("died", philo);
}

int	main(int argc, char *argv[])
{
	if ((argc == 5 || argc == 6)
		&& ft_check_args(argc, argv) && init_helper(argc, argv))
	{
		create_philos();
		check_if_philo_died();
	}
}
