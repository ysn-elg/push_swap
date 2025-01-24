/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_a_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-guad <yel-guad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:08:15 by yel-guad          #+#    #+#             */
/*   Updated: 2025/01/22 09:32:18 by yel-guad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *stack)
{
	int	i;
	int	m;

	i = 0;
	if (!stack)
		return ;
	m = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= m)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	set_a_target(t_stack *a, t_stack *b)
{
	t_stack	*curr_b;
	long	best;

	while (a)
	{
		best = LONG_MIN;
		curr_b = b;
		while (curr_b)
		{
			if (a->data > curr_b->data && curr_b->data > best)
			{
				best = curr_b->data;
				a->target_node = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (best == LONG_MIN)
			a->target_node = find_biggest(b);
		a = a->next;
	}
}

void	set_a_cost(t_stack *a, t_stack *b)
{
	int	a_len;
	int	b_len;

	a_len = ft_lstsize(a);
	b_len = ft_lstsize(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = a_len - a->index;
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += b_len - a->target_node->index;
		a = a->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest_cost;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_cost = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_cost)
		{
			cheapest_cost = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	refresh_a_nodes(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_a_target(a, b);
	set_a_cost(a, b);
	set_cheapest(a);
}
