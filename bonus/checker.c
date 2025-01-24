/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-guad <yel-guad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:57:11 by yel-guad          #+#    #+#             */
/*   Updated: 2025/01/22 10:03:08 by yel-guad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	execute(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "sa\n"))
		swap(*a);
	else if (!ft_strcmp(line, "sb\n"))
		swap(*b);
	else if (!ft_strcmp(line, "ss\n"))
		ss_2(*a, *b);
	else if (!ft_strcmp(line, "pa\n"))
		push(b, a);
	else if (!ft_strcmp(line, "pb\n"))
		push(a, b);
	else if (!ft_strcmp(line, "ra\n"))
		rotate(a);
	else if (!ft_strcmp(line, "rb\n"))
		rotate(b);
	else if (!ft_strcmp(line, "rr\n"))
		rr_2(a, b);
	else if (!ft_strcmp(line, "rra\n"))
		reverse_rotate(a);
	else if (!ft_strcmp(line, "rrb\n"))
		reverse_rotate(b);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr_2(a, b);
	else
		return (0);
	return (1);
}

static int	read_and_execute(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!execute(line, a, b))
			return (free(line), 0);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	return (1);
}

static int	ok_ko(t_stack **a, t_stack **b)
{
	if (!read_and_execute(a, b))
	{
		free_stack(a);
		free_stack(b);
		return (write(1, "Error\n", 6), -1);
	}
	if (is_sorted(*a) && !*b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(a);
	return (0);
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
		return (ok_ko(&a, &b));
	return (0);
}
