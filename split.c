/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-guad <yel-guad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:33:18 by yel-guad          #+#    #+#             */
/*   Updated: 2025/01/16 09:33:21 by yel-guad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	w;
	int		t;

	i = 0;
	w = 0;
	t = 1;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (t == 1)
				w++;
			t = 0;
		}
		else
			t = 1;
		i++;
	}
	return (w);
}

void	freeall(char **res, size_t k)
{
	while (k > 0)
		free(res[--k]);
	free(res);
}

static size_t	findend(size_t start, const char *s, char c)
{
	while (s[start] && s[start] != c)
		start++;
	return (start);
}

static char	**fillall(char const *s, char c, char **res)
{
	size_t	i;
	size_t	k;
	size_t	end;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			end = findend(i, s, c);
			res[k] = ft_substr(s, i, end - i);
			if (!res[k])
			{
				freeall(res, k);
				return (NULL);
			}
			k++;
			i = end;
		}
		else
			i++;
	}
	res[k] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	w;
	char	**res;

	if (!s)
		return (NULL);
	w = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (w + 1));
	if (!res)
		return (NULL);
	return (fillall(s, c, res));
}
