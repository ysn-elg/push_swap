/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_b_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-guad <yel-guad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:09:28 by yel-guad          #+#    #+#             */
/*   Updated: 2025/01/22 09:32:59 by yel-guad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_biggest(t_stack *stack)
{
	t_stack	*biggest;

	if (!stack)
		return (NULL);
	biggest = stack;
	while (stack)
	{
		if (stack->data > biggest->data)
			biggest = stack;
		stack = stack->next;
	}
	return (biggest);
}

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*smallest;

	if (!stack)
		return (NULL);
	smallest = stack;
	while (stack)
	{
		if (stack->data < smallest->data)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

static void	set_b_target(t_stack *a, t_stack *b)
{
	t_stack	*curr_a;
	long	best;

	while (b)
	{
		best = LONG_MAX;
		curr_a = a;
		while (curr_a)
		{
			if (b->data < curr_a->data && curr_a->data < best)
			{
				best = curr_a->data;
				b->target_node = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (best == LONG_MAX)
			b->target_node = find_smallest(a);
		b = b->next;
	}
}

void	refresh_b_nodes(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_b_target(a, b);
	set_cheapest(b);
}
