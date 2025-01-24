/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-guad <yel-guad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:02:52 by yel-guad          #+#    #+#             */
/*   Updated: 2025/01/21 16:32:24 by yel-guad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"
# include "get_next_line/get_next_line.h"

void	push(t_stack **src, t_stack **dst);
void	swap(t_stack *list);
void	rotate(t_stack **list);
void	reverse_rotate(t_stack **list);
void	ss_2(t_stack *a, t_stack *b);
void	rr_2(t_stack **a, t_stack **b);
void	rrr_2(t_stack **a, t_stack **b);

#endif
