/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 07:56:11 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/08/06 17:10:12 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, 0);
	return ((time.tv_sec) * 1000 + (time.tv_usec) / 1000);
}

long	ft_get_diff_time(long diff)
{
	return (ft_get_time() - diff);
}

void	ft_msleep(long milliseconds)
{
	long	current_time;

	current_time = ft_get_time();
	if (milliseconds > 20)
	{
		while (ft_get_diff_time(current_time) < milliseconds)
			usleep(100);
	}
}
