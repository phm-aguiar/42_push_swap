/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:13:42 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/06 18:48:03 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_xy
{
	int				x;
	int				y;
}					t_xy;
typedef struct s_stack
{
	int				value;
	int				index;
	int				weight;
	int				n_neighbour;
	int				p_neighbour;
	int				stay;
	struct s_stack	*next;
}					t_stack;

typedef struct s_ps
{
	t_xy			xy;
	t_stack			*cur_a;
	t_stack			*cur_b;
	int				size_a;
	int				size_b;
	int				index;
	void (*del)(void *);
	char			op;
}					t_ps;

t_stack				*add_value(t_stack *stack, int value);
t_stack				*create_stack(int len, char **values, int *sorted);
void				check_duplicate(t_stack *stack);
void				clear_stack(t_stack **lst, void (*del)(void *), char msg);
void				ft_swap(t_stack **a, char c);
void				ft_swap_ab(t_stack **a, t_stack **b);
void				end_add(t_stack **lst, t_stack *new_node);
t_stack				*ft_last_stack(t_stack *lst);
void				ft_push(t_stack **a, t_stack **b, char c);
void				ft_rotate_ab(t_stack **a, t_stack **b);
void				ft_rotate(t_stack **a, char c);
void				ft_rev_rotate(t_stack **stack, char c);
void				ft_rev_rotate_ab(t_stack **a, t_stack **b);
int					ft_stacksize(t_stack *lst);
int					ft_is_sorted(t_stack *stack);
void				start_with_merge(t_stack **stk_a, t_stack **stk_b);
// void				set_max(t_stack **stack);
// void				set_min(t_stack **stack);
void				set_weight(t_stack **stack);
void				set_index(t_stack **stack);
void				moviment_cust(int cust_a, int cust_b);
int					cmp_values(int a, int b);
void				ft_sort_int_tab(int *a, int size);
int					*ft_sort_array(int argc, char **argv);
void				set_neighbour(t_stack **stack, int *sorted, int size);
void				move_perfect_head(t_stack **stk_a, t_stack **stk_b);
int					search_perfect(t_stack *stk_a, t_stack *stk_b, t_ps *sp);
int					moviment_count(t_stack **stack_a, t_stack **stack_b,
						t_ps *mc);
void				init_values(t_ps *iv);

#endif