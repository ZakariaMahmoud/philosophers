/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:43:41 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/19 11:10:49 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_helper(int argc, char*argv[], t_groupe *groupe)
{
	groupe->helper.number_of_philos = ft_atoi(argv[1]);
	groupe->helper.time_to_die = ft_atoi(argv[2]);
	groupe->helper.time_to_eat = ft_atoi(argv[3]);
	groupe->helper.time_to_sleep = ft_atoi(argv[4]);
	groupe->helper.philos = malloc(groupe->helper.number_of_philos * sizeof(t_philo));
	if (argc == 5)
		groupe->helper.times_philo_must_eat   = -1;
	else
		groupe->helper.times_philo_must_eat   = ft_atoi(argv[5]);
}

void	init_philos(t_groupe *groupe)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = groupe->helper.philos;
	while (i < groupe->helper.number_of_philos)
	{
		philos[i].id = i;
		i++;
	}
}
