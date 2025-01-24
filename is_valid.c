/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-guad <yel-guad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:22:48 by yel-guad          #+#    #+#             */
/*   Updated: 2025/01/22 09:26:55 by yel-guad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	if ((str[i] == '-' || str[i] == '+') && str[i +1])
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	args_cmp_of(char *s1, char *s2)
{
	long	n;
	long	m;

	n = ft_atol(s1);
	m = ft_atol(s2);
	if (n == m || n > INT_MAX || n < INT_MIN || m > INT_MAX || m < INT_MIN)
		return (0);
	return (1);
}

int	is_valid(char **res)
{
	int	i;
	int	j;

	i = 0;
	while (res[i])
	{
		if (!is_number(res[i]))
			return (0);
		j = i + 1;
		while (res[j])
			if (args_cmp_of(res[i], res[j++]) == 0)
				return (0);
		i++;
	}
	return (1);
}
