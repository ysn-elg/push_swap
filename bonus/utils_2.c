/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-guad <yel-guad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:45:45 by yel-guad          #+#    #+#             */
/*   Updated: 2025/01/22 09:35:12 by yel-guad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	fill_stack_a(t_stack **a, char **res)
{
	int		i;
	t_stack	*tmp;
	t_stack	*node;

	i = 0;
	while (res[i])
	{
		node = ft_lstnew((int)ft_atol(res[i++]));
		if (!node)
		{
			free_stack(a);
			return ;
		}
		if (*a == NULL)
			*a = node;
		else
		{
			tmp->next = node;
			node->prev = tmp;
		}
		tmp = node;
	}
}

int	is_sorted(t_stack *a)
{
	while (a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}

void	reverse_rotate(t_stack **list)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!list || !(*list) || !(*list)->next)
		return ;
	tmp = *list;
	last = ft_lstlast(*list);
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	last->next = (*list);
	tmp->next = NULL;
	(*list) = last;
}

void	rrr_2(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
