/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:28:56 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/19 11:08:25 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	*get_philo_by_id(t_groupe *groupe, int id)
{
	t_philo 	*tmp;
	t_helper	*helper;

	helper = &groupe->helper;
	tmp = &helper->philos[id];
	if (tmp->id == id)
		return (tmp);
	return (0);
}