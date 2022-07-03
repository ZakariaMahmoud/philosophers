/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:24:05 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/07/03 12:50:53 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo(char *msg, long time, t_philo *philo)
{
	t_helper	*helper;

	helper = philo->helper;
	if (pthread_mutex_lock(&helper->writing) == 0)
	{
		printf("%ld %d %s\n", time, philo->id + 1, msg);
		pthread_mutex_unlock(&helper->writing);
	}
}

void *philo_thread(void *arg)
{
	t_philo		*philo;
	t_philo		*next_philo;
	t_helper	*helper;
	long		time;

	philo = (t_philo *) arg;
	helper = philo->helper;
	next_philo = get_next_philo(philo->helper, philo->id);
	time = ft_get_diff_time(helper->start_time);
	while (time - philo->last_meal < helper->time_to_die)
	{
		
		time = ft_get_diff_time(helper->start_time);
		if (pthread_mutex_lock(&philo->fork) == 0 && pthread_mutex_lock(&next_philo->fork) == 0)
		{
			// printf("philo->id = [ %d ] | next_philo->id = [ %d ] | Time = [ %ld ]\n", philo->id, next_philo->id, time);
			time = ft_get_diff_time(helper->start_time);
			if (philo->last_meal != 0)
				print_philo("is thinking", time, philo);
			print_philo("has taken a fork", time, philo);
			print_philo("has taken a fork", time, philo);
			print_philo("is eating", time, philo);
			ft_msleep(helper->time_to_eat);
			time = ft_get_diff_time(helper->start_time);
			philo->last_meal = time;
			print_philo("is sleeping", time, philo);
			pthread_mutex_unlock(&philo->fork);
			pthread_mutex_unlock(&next_philo->fork);
			ft_msleep(helper->time_to_sleep);
			time = ft_get_diff_time(helper->start_time);
		}
	}
	philo->time_died = time;

	// pthread_detach(philo->thread);
	
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
}

void	check_if_philo_died(t_helper *helper)
{
	t_philo		*philo;
	int			i;

	i = 0;
	while (1)
	{
		philo = get_philo_by_id(helper, i++);
		if (philo->time_died != -1)
			break;
		if (i == helper->number_of_philos)
			i = 0;
	}
	print_philo("died", philo->time_died, philo);
	pthread_mutex_lock(&philo->helper->writing);
}

int	main(int argc, char *argv[])
{
	t_helper helper;
	if ((argc == 5 || argc == 6) && ft_check_args(argc, argv))
	{ 
		init_helper(argc, argv, &helper);
		odd_philos(&helper);
		even_philos(&helper);
		// joins_philo(&helper);
		check_if_philo_died(&helper);
		// while (1);
	}
}
