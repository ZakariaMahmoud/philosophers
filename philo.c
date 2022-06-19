/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:24:05 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/19 12:36:04 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void *philo_thread(void *args)
{
	t_groupe *groupe;

	groupe = (t_groupe *) args;
	printf("philo id => %d\n", groupe->philo.id);
	return (0);
}

void	odd_philos(t_groupe *groupe)
{
	int			i;
	t_philo		*tmp;

	i = 0;
	while (i < groupe->helper.number_of_philos)
	{
		tmp = get_philo_by_id(groupe, i);
		if (tmp)
		{
			groupe->philo = *tmp;
			pthread_create(&(tmp->thread), NULL, &philo_thread, groupe);
			pthread_join(tmp->thread, NULL);
		}
		i += 2;
	}
}

int	main(int argc, char *argv[])
{
	t_groupe groupe;
	if ((argc == 5 || argc == 6) && ft_check_args(argc, argv))
	{ 
		init_helper(argc, argv, &groupe);
		init_philos(&groupe);
		odd_philos(&groupe);
	}

}