/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeenyt <zeenyt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:13:42 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/29 20:52:15 by zeenyt           ###   ########.fr       */
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
	struct s_stack	*next;
	struct s_stack	*previous;
}					t_stack;

t_stack				*add_value(t_stack *stack, int value);
t_stack				*create_stack(int len, char **values);
t_stack				*create_stack_b(int value);
void				check_duplicate(t_stack *stack);
void				clear_stack(t_stack **lst, void (*del)(void *), char *msg);
void				ft_swap_a(t_stack **a);
void				ft_swap_b(t_stack **b);
void				ft_swap_ab(t_stack **a, t_stack **b);
void				end_add(t_stack **lst, t_stack *new_node);
t_stack				*ft_last_stack(t_stack *lst);
void				ft_push_a(t_stack **a, t_stack **b);
void				ft_push_b(t_stack **a, t_stack **b);
void				ft_pop(t_stack **head);

#endif