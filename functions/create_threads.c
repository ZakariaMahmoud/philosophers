/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:17:51 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/07/25 12:01:46 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	create_philos()
{
	create_even_philos();
	create_odd_philos();
}

void	create_even_philos()
{
	int		id;
	t_philo	*philos;

	id = 0;
	philos = t_helper.philos;
	while (id < t_helper.number_of_philos)
	{
		pthread_create(&philos[id].thread, 0, &philo_thread, &philos[id]);
		id += 2;
	}
}

void	create_odd_philos()
{
	int		id;
	t_philo	*philos;

	id = 1;
	philos = t_helper.philos;
	while (id < t_helper.number_of_philos)
	{
		pthread_create(&philos[id].thread, 0, &philo_thread, &philos[id]);
		id += 2;
	}
}