/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:13:42 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/03 16:12:38 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	int				high;
	int				low;
	int				index;
	struct s_stack	*next;
}					t_stack;

t_stack				*add_value(t_stack *stack, int value);
t_stack				*create_stack(int len, char **values);
t_stack				*create_stack_b(int value);
void				check_duplicate(t_stack *stack);
void				clear_stack(t_stack **lst, void (*del)(void *), char *msg);
void				ft_swap(t_stack **a, char c);
void				ft_swap_ab(t_stack **a, t_stack **b);
void				end_add(t_stack **lst, t_stack *new_node);
t_stack				*ft_last_stack(t_stack *lst);
void				ft_push(t_stack **a, t_stack **b, char c);
void				ft_rotate_ab(t_stack **a, t_stack **b);
void				ft_rotate(t_stack **a, char c);
void				ft_rev_rotate(t_stack **stack, char c);
int					ft_stacksize(t_stack *lst);
void				find_high(t_stack **a);
void				find_low(t_stack **a);
void				min_to_b(t_stack **a, t_stack **b);
void				assign_index(t_stack **a);

#endif