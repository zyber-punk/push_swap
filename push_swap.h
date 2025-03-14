/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:26:17 by uzyberaj          #+#    #+#             */
/*   Updated: 2025/03/13 18:00:24 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	int					rotation_method;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

typedef struct s_calc
{
	int		z;
	int		m;
}	t_calc;

char			**ft_split(char *str, char separator);

void			free_matrix(char **argv);
void			error_free(t_stack_node **a, char **argv, bool flag_argc_2);
void			free_stack(t_stack_node **stack);
int				error_repetition(t_stack_node *a, int nbr);
int				error_syntax(char *str_nbr);

void			stack_init(t_stack_node **a, char **argv, bool flag_argc_2);
void			init_nodes(t_stack_node *a, t_stack_node *b);
void			set_current_position(t_stack_node *stack);
void			set_price(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *b);

void			append_node(t_stack_node **stack, int nbr);
t_stack_node	*find_last_node(t_stack_node *head);
t_stack_node	*find_smallest(t_stack_node *stack);
t_stack_node	*return_cheapest(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
void			finish_rotation(t_stack_node **s, t_stack_node *n, char c);

void			tiny_sort(t_stack_node **a);
void			handle_five(t_stack_node **a, t_stack_node **b);
void			push_swap(t_stack_node **a, t_stack_node **b);

void			sa(t_stack_node **a, bool checker);
void			sb(t_stack_node **b, bool checker);
void			ss(t_stack_node **a, t_stack_node **b, bool checker);
void			ra(t_stack_node **a, bool checker);
void			rb(t_stack_node **b, bool checker);
void			rr(t_stack_node **a, t_stack_node **b, bool checker);
void			rra(t_stack_node **a, bool checker);
void			rrb(t_stack_node **b, bool checker);
void			rrr(t_stack_node **a, t_stack_node **b, bool checker);
void			pa(t_stack_node **a, t_stack_node **b, bool checker);
void			pb(t_stack_node **b, t_stack_node **a, bool checker);

void			update_optimal_price(t_stack_node *b, int len_b, int len_a);
void			set_initial_z_m(t_stack_node *node, t_calc *calc);
void			update_method_2(t_stack_node *node,
					int len_b, int len_a, t_calc *calc);
void			update_method_3(t_stack_node *node, int len_a, t_calc *calc);
void			update_method_4(t_stack_node *node, int len_b, t_calc *calc);

void			rotate_both_up(t_stack_node **a, t_stack_node **b,
					int cost_b_up, int cost_a_up);
void			rotate_both_down(t_stack_node **a, t_stack_node **b,
					int cost_b_down, int cost_a_down);
void			rotate_b_up_a_down(t_stack_node **a, t_stack_node **b,
					int cost_b_up, int cost_a_down);
void			rotate_b_down_a_up(t_stack_node **a, t_stack_node **b,
					int cost_b_down, int cost_a_up);

t_stack_node	*get_target_node(t_stack_node *a, int value);

#endif