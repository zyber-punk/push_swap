/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_price.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 01:52:39 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/03/13 17:59:50 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_initial_z_m(t_stack_node *node, t_calc *calc)
{
	int		x;
	int		y;

	x = node->current_position;
	y = node->target_node->current_position;
	if (x > y)
		calc->z = x;
	else
		calc->z = y;
	calc->m = 1;
}

void	update_method_2(t_stack_node *node,
							int len_b,
							int len_a,
							t_calc *calc)
{
	int		tmp;

	tmp = len_b - node->current_position;
	if ((len_a - node->target_node->current_position) > tmp)
		tmp = len_a - node->target_node->current_position;
	if (tmp < calc->z)
	{
		calc->z = tmp;
		calc->m = 2;
	}
}

void	update_method_3(t_stack_node *node, int len_a, t_calc *calc)
{
	int		tmp;

	tmp = node->current_position + \
	(len_a - node->target_node->current_position);
	if (tmp < calc->z)
	{
		calc->z = tmp;
		calc->m = 3;
	}
}

void	update_method_4(t_stack_node *node, int len_b, t_calc *calc)
{
	int		tmp;

	tmp = (len_b - node->current_position) + \
	node->target_node->current_position;
	if (tmp < calc->z)
	{
		calc->z = tmp;
		calc->m = 4;
	}
}

void	update_optimal_price(t_stack_node *b, int len_b, int len_a)
{
	t_stack_node	*temp;
	t_calc			calc;

	temp = b;
	while (temp)
	{
		set_initial_z_m(temp, &calc);
		update_method_2(temp, len_b, len_a, &calc);
		update_method_3(temp, len_a, &calc);
		update_method_4(temp, len_b, &calc);
		temp->push_price = calc.z;
		temp->rotation_method = calc.m;
		temp = temp->next;
	}
}
