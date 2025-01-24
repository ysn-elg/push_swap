/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-guad <yel-guad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:54:46 by yel-guad          #+#    #+#             */
/*   Updated: 2025/01/22 09:25:01 by yel-guad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_cheapest(t_stack *stack)
{
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

static void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*xp;

	xp = get_cheapest(*a);
	if (!xp || !xp->target_node)
		return ;
	if ((xp->above_median && xp->target_node->above_median))
		rotate_both(a, b, xp);
	else if (!(xp->above_median) && !(xp->target_node->above_median))
		reverse_rotate_both(a, b, xp);
	else if ((!(xp->above_median) && (xp->target_node->above_median))
		&& xp->index < xp->target_node->index)
		rotate_both(a, b, xp);
	else if ((xp->above_median && !(xp->target_node->above_median))
		&& ft_lstsize(*a) - xp->index < ft_lstsize(*b) - xp->target_node->index)
		reverse_rotate_both(a, b, xp);
	finish_rotation(a, xp, 'a');
	finish_rotation(b, xp->target_node, 'b');
	pb(a, b);
}

static void	move_b_to_a(t_stack **a, t_stack **b)
{
	finish_rotation(a, (*b)->target_node, 'a');
	pa(b, a);
}

static void	min_to_top(t_stack **a)
{
	t_stack	*smallest;

	smallest = find_smallest(*a);
	while ((*a)->data != smallest->data)
	{
		if (smallest->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	sort(t_stack **a, t_stack **b)
{
	int	a_len;

	a_len = ft_lstsize(*a);
	if (a_len-- > 3 && !is_sorted(*a))
		pb(a, b);
	if (a_len-- > 3 && !is_sorted(*a))
		pb(a, b);
	while (a_len-- > 3 && !is_sorted(*a))
	{
		refresh_a_nodes(*a, *b);
		move_a_to_b(a, b);
	}
	tiny_sort(a);
	while (*b)
	{
		refresh_b_nodes(*a, *b);
		move_b_to_a(a, b);
	}
	set_index(*a);
	min_to_top(a);
}
