/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-guad <yel-guad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:33:58 by yel-guad          #+#    #+#             */
/*   Updated: 2025/01/22 09:23:17 by yel-guad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_else(int i, int *j, char **av, char **res) // 3 "11 4 -2"
{
	char	**tmp;
	int		k;

	tmp = ft_split(av[i], ' ');
	if (!tmp)
		return (0);
	k = 0;
	while (tmp[k])
	{
		res[*j] = ft_strdup(tmp[k]);
		if (!res[*j])
		{
			freeall(res, *j);
			while (tmp[k])
				free(tmp[k++]);
			free(tmp);
			return (0);
		}
		free(tmp[k++]);
		(*j)++;
	}
	free(tmp);
	return (1);
}

char	**fillargs(int ac, char **av, char **res)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		if (count_words(av[i], ' ') == 0)
			i++;
		else if (count_words(av[i], ' ') == 1)
		{
			res[j] = ft_strdup(av[i++]);
			if (!res[j++])
				return (freeall(res, --j), NULL);
		}
		else
		{
			if (!ft_else(i++, &j, av, res))
				return (NULL);
		}
	}
	res[j] = NULL;
	if (!res[0])
		return (freeall(res, 1), NULL);
	return (res);
}

char	**split_args(int ac, char **av) // 1 21 "3 48 5pp" 6 
{
	char	**res;
	int		i;
	int		tw;

	i = 1;
	tw = 0;
	while (i < ac)
		tw += count_words(av[i++], ' ');
	res = (char **)malloc((tw +1) * sizeof(char *));
	if (!res)
		return (NULL);
	return (fillargs(ac, av, res));
}
