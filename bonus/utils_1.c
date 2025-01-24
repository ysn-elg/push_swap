/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-guad <yel-guad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:54:39 by yel-guad          #+#    #+#             */
/*   Updated: 2025/01/22 10:04:39 by yel-guad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
}

void	swap(t_stack *stack)
{
	int	tmp;

	if (!stack)
		return ;
	tmp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = tmp;
}

void	ss_2(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	rotate(t_stack **list)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!list || !(*list) || !(*list)->next)
		return ;
	tmp = *list;
	(*list) = (*list)->next;
	tmp->next = NULL;
	last = ft_lstlast(*list);
	last->next = tmp;
}

void	rr_2(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
