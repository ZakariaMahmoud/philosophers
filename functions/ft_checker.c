/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:14:39 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/06/16 11:00:58 by zmahmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	is_strdigit(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i++]))
			return (0);
	}
	return (1);
}

int	ft_check_args(int argc, char *argv[])
{
	int	i;	

	i = 1;
	while (i < argc)
	{
		if (!(is_strdigit(argv[i])
				|| (argv[i][0] == '-' && is_strdigit(&argv[i][1]))
				|| (argv[i][0] == '+' && is_strdigit(&argv[i][1]))))
		{
				return (0);
		}
		i++;
	}
	return (1);
}
