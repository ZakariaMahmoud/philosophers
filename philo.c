/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:24:05 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/08/01 12:46:48 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	main(int argc, char *argv[])
{
	if ((argc == 5 || argc == 6) && ft_check_args(argc, argv) && init_helper(argc, argv))
	{
		create_philos();
		while(1);
	}
}
