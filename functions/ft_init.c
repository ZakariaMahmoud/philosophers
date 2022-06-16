/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:43:41 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/16 11:53:45 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_helper(int argc, char*argv[], t_helper *helper)
{
	helper->number_of_philosophers = ft_atoi(argv[1]);
	helper->time_to_eat = ft_atoi(argv[2]);
	helper->time_to_sleep = ft_atoi(argv[3]);
	helper->time_to_die = ft_atoi(argv[4]);
	if(argc == 5)
		helper->times_philo_must_eat   = -1;
	else
		helper->times_philo_must_eat   = ft_atoi(argv[5]);
}