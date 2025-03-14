/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 01:59:15 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/03/13 18:00:01 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both_up(t_stack_node **a, t_stack_node **b,
						int cost_b_up, int cost_a_up)
{
	int		common;
	int		i;

	if (cost_b_up <= cost_a_up)
		common = cost_b_up;
	else
		common = cost_a_up;
	i = 0;
	while (i < common)
	{
		rr(a, b, false);
		i = i + 1;
	}
	i = common;
	while (i < cost_b_up)
	{
		rb(b, false);
		i = i + 1;
	}
	i = common;
	while (i < cost_a_up)
	{
		ra(a, false);
		i = i + 1;
	}
}

void	rotate_both_down(t_stack_node **a, t_stack_node **b,
						int cost_b_down, int cost_a_down)
{
	int		common;
	int		i;

	if (cost_b_down <= cost_a_down)
		common = cost_b_down;
	else
		common = cost_a_down;
	i = 0;
	while (i < common)
	{
		rrr(a, b, false);
		i = i + 1;
	}
	i = common;
	while (i < cost_b_down)
	{
		rrb(b, false);
		i = i + 1;
	}
	i = common;
	while (i < cost_a_down)
	{
		rra(a, false);
		i = i + 1;
	}
}

void	rotate_b_up_a_down(t_stack_node **a, t_stack_node **b,
							int cost_b_up, int cost_a_down)
{
	int		i;

	i = 0;
	while (i < cost_b_up)
	{
		rb(b, false);
		i = i + 1;
	}
	i = 0;
	while (i < cost_a_down)
	{
		rra(a, false);
		i = i + 1;
	}
}

void	rotate_b_down_a_up(t_stack_node **a, t_stack_node **b,
							int cost_b_down, int cost_a_up)
{
	int		i;

	i = 0;
	while (i < cost_b_down)
	{
		rrb(b, false);
		i = i + 1;
	}
	i = 0;
	while (i < cost_a_up)
	{
		ra(a, false);
		i = i + 1;
	}
}
