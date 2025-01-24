/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-guad <yel-guad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:27:13 by yel-guad          #+#    #+#             */
/*   Updated: 2025/01/09 15:16:23 by yel-guad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **list)
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

void	rra(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
