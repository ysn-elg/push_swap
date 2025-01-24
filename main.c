/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-guad <yel-guad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:20:39 by yel-guad          #+#    #+#             */
/*   Updated: 2025/01/22 10:08:57 by yel-guad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	is_sorted(t_stack *a) // 2 3 4 8 9 1
{
	while (a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}

void	tiny_sort(t_stack **a)
{
	if ((*a)->data > (*a)->next->data && (*a)->data > (*a)->next->next->data)
		ra(a);
	else if ((*a)->next->data > (*a)->data
		&& (*a)->next->data > (*a)->next->next->data)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(*a);
}

static void	push_swap(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 2)
		sa(*a);
	else if (ft_lstsize(*a) == 3)
		tiny_sort(a);
	else
		sort(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**res;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (-1);
	res = split_args(ac, av);
	if (!res)
		return (-1);
	if (!is_valid(res))
		return (freeall(res, ft_2strlen(res)), write(1, "Error\n", 6), -1);
	fill_stack_a(&a, res);
	freeall(res, ft_2strlen(res));
	if (!is_sorted(a))
		push_swap(&a, &b);
	free_stack(&a);
}
