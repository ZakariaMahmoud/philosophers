/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:28:56 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/07/24 23:05:21 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	*get_philo_by_id(int id)
{
	if (id < t_helper.number_of_philos)
		return (&t_helper.philos[id]);
	return (0);
}

t_philo	*get_next_philo_by_id(int id)
{
	if (id + 1 < t_helper.number_of_philos)
		return (&t_helper.philos[id + 1]);
	else if (id + 1 == t_helper.number_of_philos)
		return (&t_helper.philos[0]);
	return (0);
}