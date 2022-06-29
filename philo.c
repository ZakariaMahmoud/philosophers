/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:24:05 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/29 10:30:17 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void *philo_thread(void *arg)
{
	t_philo		*philo;
	t_philo		*next_philo;
	t_helper	*helper;
	long		time;

	philo = (t_philo *) arg;
	helper = philo->helper;
	next_philo = get_next_philo(philo->helper, philo->id);
	while (1)
	{
		time = ft_get_diff_time(helper->start_time);
		if (time % helper->time_to_eat == 0)
		{
			pthread_mutex_lock(&philo->fork);
			pthread_mutex_lock(&next_philo->fork);
			printf("%ld %d has taken a fork\n", ft_get_diff_time(philo->helper->start_time), philo->id + 1);
			printf("%ld %d has taken a fork\n", ft_get_diff_time(philo->helper->start_time), philo->id + 1);
			printf("%ld %d is eating\n", ft_get_diff_time(philo->helper->start_time), philo->id + 1);
			usleep(helper->time_to_eat * 1000);
			pthread_mutex_unlock(&next_philo->fork);
			pthread_mutex_unlock(&philo->fork);
		}
		if (time % helper->time_to_sleep == 0)
		{
			printf("%ld %d is sleeping\n", ft_get_diff_time(philo->helper->start_time), philo->id + 1);
			usleep(helper->time_to_sleep * 1000);
		}
		
	}
	return (0);
}

void	odd_philos(t_helper *helper)
{
	int			i;
	t_philo		*tmp;

	i = 0;
	while (i < helper->number_of_philos)
	{
		tmp = get_philo_by_id(helper, i);
		if (tmp)
			pthread_create(&(tmp->thread), 0, &philo_thread, tmp);
		i += 2;
	}
	i = 0;
	while (i < helper->number_of_philos)
	{
		tmp = get_philo_by_id(helper, i);
		if (tmp)
			pthread_join(tmp->thread, 0);
		i += 2;
	}
}

void	even_philos(t_helper *helper)
{
	int			i;
	t_philo		*tmp;

	i = 1;
	while (i < helper->number_of_philos)
	{
		tmp = get_philo_by_id(helper, i);
		if (tmp)
			pthread_create(&(tmp->thread), 0, &philo_thread, tmp);
		i += 2;
	}
	i = 1;
	while (i < helper->number_of_philos)
	{
		tmp = get_philo_by_id(helper, i);
		if (tmp)
			pthread_join(tmp->thread, 0);
		i += 2;
	}
}

int	main(int argc, char *argv[])
{
	t_helper helper;
	if ((argc == 5 || argc == 6) && ft_check_args(argc, argv))
	{ 
		init_helper(argc, argv, &helper);
		odd_philos(&helper);
		even_philos(&helper);
	}
}
