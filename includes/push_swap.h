/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:13:42 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/05 19:38:11 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	unsigned int	weight;
	int				min;
	int				max;
	int				index;
	struct s_stack	*next;
}					t_stack;

t_stack				*add_value(t_stack *stack, int value);
t_stack				*create_stack(int len, char **values);
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
int					ft_stacksize(t_stack *lst);
int					ft_is_sorted(t_stack *stack);
void				start_with_merge(t_stack **stk_a, t_stack **stk_b);
void				set_max(t_stack **stack);
void				set_min(t_stack **stack);
void				set_weight(t_stack **stack);
void				set_index(t_stack **stack);
void				quicksort(t_stack **stack);
void				moviment_cust(int cust_a, int cust_b);
int					cmp_values(int a, int b);

#endif