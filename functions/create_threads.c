/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:17:51 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/08/11 02:38:36 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	create_philos(t_helper *helper)
{
	create_even_philos(helper);
}

void	create_even_philos(t_helper *helper)
{
	int		id;
	t_philo	*philos;

	id = 0;
	philos = helper->philos;
	while (id < helper->number_of_philos)
	{
		pthread_create(&philos[id].thread, 0, &philo_thread, &philos[id]);
		id += 2;
	}
	usleep((helper->time_to_eat / 2) * 1000);
	create_odd_philos(helper);
}

void	create_odd_philos(t_helper *helper)
{
	int		id;
	t_philo	*philos;

	id = 1;
	philos = helper->philos;
	while (id < helper->number_of_philos)
	{
		pthread_create(&philos[id].thread, 0, &philo_thread, &philos[id]);
		id += 2;
	}
}
