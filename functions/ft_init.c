/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:43:41 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/07/03 12:41:39 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_helper(int argc, char*argv[], t_helper *helper)
{
	helper->number_of_philos = ft_atoi(argv[1]);
	helper->time_to_die = ft_atoi(argv[2]);
	helper->time_to_eat = ft_atoi(argv[3]);
	helper->time_to_sleep = ft_atoi(argv[4]);
	helper->start_time = ft_get_time();
	helper->philos = malloc(helper->number_of_philos * sizeof(t_philo));
	pthread_mutex_init(&helper->writing, 0);
	if (argc == 5)
		helper->times_philo_must_eat   = -1;
	else
		helper->times_philo_must_eat   = ft_atoi(argv[5]);
	init_philos(helper);
}

void	init_philos(t_helper *helper)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = helper->philos;
	while (i < helper->number_of_philos)
	{
		philos[i].id = i;
		philos[i].last_meal = 0;
		philos[i].time_died = -1;
		philos[i].helper = helper;
		pthread_mutex_init(&philos[i].fork, 0);
		i++;
	}
}
