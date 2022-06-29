/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:28:56 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/23 19:43:58 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	*get_philo_by_id(t_helper *helper, int id)
{
	if (id < helper->number_of_philos)
		return (&helper->philos[id]);
	return (0);
}

t_philo	*get_next_philo(t_helper *helper, int id)
{
	if (id + 1 < helper->number_of_philos)
		return (&helper->philos[id + 1]);
	else if (id + 1 == helper->number_of_philos)
		return (&helper->philos[0]);
	return (0);
}