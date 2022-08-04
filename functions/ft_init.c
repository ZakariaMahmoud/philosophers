/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:43:41 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/08/04 19:57:04 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_helper(int argc, char*argv[])
{
	s_helper.number_of_philos = ft_atoi(argv[1]);
	s_helper.time_to_die = ft_atoi(argv[2]);
	s_helper.time_to_eat = ft_atoi(argv[3]);
	s_helper.time_to_sleep = ft_atoi(argv[4]);
	s_helper.start_time = ft_get_time();
	pthread_mutex_init(&s_helper.writing, 0);
	s_helper.philos = malloc(s_helper.number_of_philos * sizeof(t_philo));
	if (!s_helper.philos)
		return (0);
	if (argc == 5)
		s_helper.times_philo_must_eat = -1;
	else
		s_helper.times_philo_must_eat = ft_atoi(argv[5]);
	init_philos();
	return (1);
}

void	init_philos(void)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = s_helper.philos;
	while (i < s_helper.number_of_philos)
	{
		philos[i].id = i;
		philos[i].last_meal = 0;
		philos[i].must_eat = 0;
		pthread_mutex_init(&philos[i].m_last_meal, 0);
		pthread_mutex_init(&philos[i].fork, 0);
		i++;
	}
}
