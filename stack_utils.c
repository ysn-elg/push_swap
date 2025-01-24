/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-guad <yel-guad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:56:43 by yel-guad          #+#    #+#             */
/*   Updated: 2025/01/22 09:28:01 by yel-guad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = content;
	node->above_median = 0;
	node->push_cost = INT_MAX;
	node->next = NULL;
	node->prev = NULL;
	node->target_node = NULL;
	node->cheapest = false;
	return (node);
}

int	ft_lstsize(t_stack *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!lst)
		return ;
	last = ft_lstlast(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*curr;

	curr = *stack;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	*stack = (NULL);
}
