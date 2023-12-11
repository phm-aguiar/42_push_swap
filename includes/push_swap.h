/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:13:42 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/10 20:18:54 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_push	t_ps;

/**
 * @brief Struct to store the stack
 * @param value The value of the stack
 * @param next The next stack
 * @param order The index of the stack
 * @param next_even The next even stack
 * @param next_odd The next odd stack
 * @param previous_even The previous even stack
 * @param previous_odd The previous odd stack
 */

typedef struct s_stack
{
	int					value;
	int					index;
	int					next_n;
	int					stack_id;
	struct s_stack		*next;
}						t_stack;

typedef struct s_xy
{
	int					x;
	int					y;
}						t_xy;

typedef struct s_error
{
	void				(*first)(void);
	void				(*mid)(t_ps *sfe);
	void				(*last)(t_ps *sfs);
}						t_error;

typedef struct s_push
{
	t_stack				*stack_a;
	t_stack				*stack_b;
	int					*sorted_array;
	int					size;
	char				**unsorted_values;
	t_error				status;
}						t_ps;

// init_system.c

void					configure_system(t_ps *scs, int argc, char **argv);
void					configure_node_index(t_ps *scni);
void					configure_node_neighbors(t_ps *scnne);

// status_system.c

void					initial_errors(void);
void					ft_error(t_ps *sfe);
void					ft_success(t_ps *sfs);
void					clean_lst(t_stack *lst);

// sort_tab_system.c

void					initialize_and_sort(t_ps *sias);

// inicialize_list_system.c

int						is_lst_sorted(t_stack *stack);
void					end_add(t_stack **lst, t_stack *new_node);
t_stack					*ft_last(t_stack *lst);
t_stack					*create_stack(t_ps *scs);
int						ft_stacksize(t_stack *stack);

// system_input_validation.c

void					check_input_duplicate(t_ps *scid);
void					check_input_overflow(t_ps *scio);
void					check_input_non_numeric(t_ps *scin);

// system_sort.c

void					merge_stack(t_ps *sms);

// data_tratament_system.c

void					initialize_data_structures(t_ps *sids);

// pedrosort.c

t_xy					find_perfect_next(t_stack **stack_a);
t_xy					find_perfect_prev(t_stack **stack_a);
void					teste_sort_prev(t_stack **stack_a);
void					teste_sort_next(t_stack **stack_a);

// operations_system.c
// pa and pb
void					push_a(t_stack **stack_a, t_stack **stack_b);
void					push_b(t_stack **stack_a, t_stack **stack_b);
// ra and rb and rr
void					rotate_a(t_stack **stack_a);
void					rotate_b(t_stack **stack_b);
void					rotate_rr(t_stack **stack_a, t_stack **stack_b);
// rra and rrb and rrr
void					reverse_rotate_a(t_stack **stack_a);
void					reverse_rotate_b(t_stack **stack_b);
void					reverse_rotate_rrr(t_stack **stack_a,
							t_stack **stack_b);
// sa and sb and ss
void					swap_a(t_stack **stack_a);
void					swap_b(t_stack **stack_b);
void					swap_ss(t_stack **stack_a, t_stack **stack_b);

// temporary_system.c

void					print_tab(t_ps *spt);
void					print_stack(t_ps *sps, char c);

#endif