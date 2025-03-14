/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:22:13 by uzyberaj          #+#    #+#             */
/*   Updated: 2025/03/13 18:00:53 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_rotation(t_stack_node **stack,
							t_stack_node *top_node,
							char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

static void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*node;
	int				cost_b_up;
	int				cost_b_down;
	int				cost_a_up;
	int				cost_a_down;

	node = return_cheapest(*b);
	set_current_position(*a);
	set_current_position(*b);
	cost_b_up = node->current_position;
	cost_b_down = stack_len(*b) - node->current_position;
	cost_a_up = node->target_node->current_position;
	cost_a_down = stack_len(*a) - node->target_node->current_position;
	if (node->rotation_method == 1)
		rotate_both_up(a, b, cost_b_up, cost_a_up);
	else if (node->rotation_method == 2)
		rotate_both_down(a, b, cost_b_down, cost_a_down);
	else if (node->rotation_method == 3)
		rotate_b_up_a_down(a, b, cost_b_up, cost_a_down);
	else if (node->rotation_method == 4)
		rotate_b_down_a_up(a, b, cost_b_down, cost_a_up);
	pa(a, b, false);
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;
	int				len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		handle_five(a, b);
	else
	{
		while (len_a-- > 3)
			pb(b, a, false);
	}
	tiny_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}
