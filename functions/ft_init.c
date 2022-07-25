/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:43:41 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/07/24 22:08:06 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_helper(int argc, char*argv[])
{
	t_helper.number_of_philos = ft_atoi(argv[1]);
	t_helper.time_to_die = ft_atoi(argv[2]);
	t_helper.time_to_eat = ft_atoi(argv[3]);
	t_helper.time_to_sleep = ft_atoi(argv[4]);
	t_helper.start_time = ft_get_time();
	pthread_mutex_init(&t_helper.writing, 0);
	t_helper.philos = malloc(t_helper.number_of_philos * sizeof(t_philo));
	if (!t_helper.philos)
		return (0);
	if (argc == 5)
		t_helper.times_philo_must_eat   = -1;
	else
		t_helper.times_philo_must_eat   = ft_atoi(argv[5]);
	init_philos();
	return (1);
}

void	init_philos()
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = t_helper.philos;
	while (i < t_helper.number_of_philos)
	{
		philos[i].id = i;
		philos[i].last_meal = 0;
		pthread_mutex_init(&philos[i].fork, 0);
		i++;
	}
}
