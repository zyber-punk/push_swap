/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 02:08:47 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/03/13 17:59:03 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*get_target_node(t_stack_node *a, int value)
{
	t_stack_node	*target;
	long			best;

	target = NULL;
	best = LONG_MAX;
	while (a)
	{
		if (a->value > value && a->value < best)
		{
			best = a->value;
			target = a;
		}
		a = a->next;
	}
	return (target);
}
