/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 07:56:11 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/28 18:24:23 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long 	ft_get_time()
{
	struct timeval	time;

	gettimeofday(&time, 0);	
	return ((time.tv_sec) * 1000 + (time.tv_usec) / 1000);
}

long 	ft_get_diff_time(long diff)
{
	struct timeval	time;
	long			now;

	gettimeofday(&time, 0);	
	now = (time.tv_sec) * 1000 + (time.tv_usec) / 1000;
	return (now - diff);
}