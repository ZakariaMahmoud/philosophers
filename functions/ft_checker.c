/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahmoud <zmahmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:14:39 by zmahmoud          #+#    #+#             */
/*   Updated: 2022/08/04 21:47:12 by zmahmoud         ###   ########.fr       */
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
				|| (argv[i][0] == '+' && is_strdigit(&argv[i][1]))))
		{
			printf("Syntax error\n");
			return (0);
		}
		if (ft_atoi(argv[1]) <= 0 || (argc == 6 && ft_atoi(argv[5]) <= 0))
			return (0);
		i++;
	}
	return (1);
}
