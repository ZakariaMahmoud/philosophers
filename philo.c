/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:24:05 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/08/02 14:56:02 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_must_eat()
{
	t_philo		*philo;
	int			i;

	i = 0;
	while (i < t_helper.number_of_philos)
	{
		philo = get_philo_by_id(i++);
		if (philo->must_eat < t_helper.times_philo_must_eat)
			return (0);
	}
	return (1);
}

void	check_if_philo_died()
{
	t_philo		*philo;
	long		time;
	int			i;

	i = 0;
	while (1)
	{
		philo = get_philo_by_id(i++);
		time = ft_get_diff_time(t_helper.start_time);
		if (i == t_helper.number_of_philos)
			i = 0;
		if (pthread_mutex_lock(&philo->m_last_meal) == 0)
		{
			if (time - philo->last_meal > t_helper.time_to_die || (t_helper.times_philo_must_eat != -1 && check_must_eat()))
				break ;
			pthread_mutex_unlock(&philo->m_last_meal);
		}
	}
	if (time - philo->last_meal > t_helper.time_to_die)
		print_philo("died", philo);
}

int	main(int argc, char *argv[])
{
	if ((argc == 5 || argc == 6) && ft_check_args(argc, argv) && init_helper(argc, argv))
	{
		create_philos();
		check_if_philo_died();
	}
}
