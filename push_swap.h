/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-guad <yel-guad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:21:17 by yel-guad          #+#    #+#             */
/*   Updated: 2025/01/22 09:22:08 by yel-guad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>

# include <stdio.h> //remove

typedef struct s_stack
{
	int				data;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

char	**split_args(int ac, char **av);
char	**ft_split(char const *s, char c);
size_t	count_words(const char *s, char c);
void	freeall(char **res, size_t k);
int		is_valid(char **res);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
long	ft_atol(char *str);
int		ft_2strlen(char **res);
void	fill_stack_a(t_stack **a, char **res);

void	free_stack(t_stack **stack);
t_stack	*ft_lstnew(int content);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int		is_sorted(t_stack *a);
void	set_cheapest(t_stack *stack);
void	set_index(t_stack *stack);
void	finish_rotation(t_stack **stack, t_stack *cheapest_node, char x);
void	tiny_sort(t_stack **a);
t_stack	*find_biggest(t_stack *stack);
t_stack	*find_smallest(t_stack *stack);

void	sort(t_stack **a, t_stack **b);

void	tiny_sort(t_stack **a);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack **b, t_stack **a);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	finish_rotation(t_stack **stack, t_stack *cheapest_node, char x);
void	refresh_a_nodes(t_stack *a, t_stack *b);
void	refresh_b_nodes(t_stack *a, t_stack *b);

#endif