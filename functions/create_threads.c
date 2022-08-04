/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:17:51 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/08/04 19:54:52 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	create_philos(void)
{
	create_even_philos();
}

void	create_even_philos(void)
{
	int		id;
	t_philo	*philos;

	id = 0;
	philos = s_helper.philos;
	while (id < s_helper.number_of_philos)
	{
		pthread_create(&philos[id].thread, 0, &philo_thread, &philos[id]);
		id += 2;
	}
	usleep(100);
	create_odd_philos();
}

void	create_odd_philos(void)
{
	int		id;
	t_philo	*philos;

	id = 1;
	philos = s_helper.philos;
	while (id < s_helper.number_of_philos)
	{
		pthread_create(&philos[id].thread, 0, &philo_thread, &philos[id]);
		id += 2;
	}
}
