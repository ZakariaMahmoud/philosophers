/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 07:56:11 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/07/02 20:54:56 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	ft_get_time(void)
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

void	ft_msleep(int milliseconds)
{
	int		micros;
	long	current_time;

	micros = (milliseconds - 10) * 1000;
	current_time = ft_get_time();
	if (milliseconds > 20)
	{
		usleep(micros);
		while (ft_get_diff_time(current_time) != milliseconds)
			usleep(100);
	}
}
