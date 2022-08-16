/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:39:39 by sryou             #+#    #+#             */
/*   Updated: 2022/07/29 14:00:52 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

typedef struct s_node{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack{
	int		size;
	t_node	*front;
	t_node	*back;		
}	t_stack;

typedef struct s_data{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*operation;
}	t_data;

typedef struct s_pivot{
	int	small;
	int	big;
}	t_pivot;

t_node	*stack_newnode(int value);
void	stack_push_back(t_stack *st, int value);
void	stack_push_front(t_stack *st, int value);
int		stack_pop_back(t_stack *st);
int		stack_pop_front(t_stack *st);
void	stack_delnode(t_node *node);
void	stack_clear(t_stack *st);

t_data	*init_data(void);
void	free_data(t_data *data);

int		is_valid_int(char *str);
int		is_valid_stack(t_stack *st);

int		*stack_to_array(t_stack *st, int size);
void	stack_operate(t_data *data, char *op);

int		stack_switch(t_stack *st);
int		stack_move(t_stack *st_dest, t_stack *st_src);
int		stack_reverse(t_stack *st);
int		stack_rereverse(t_stack *st);

int		select_pivot(t_data *data, int size, char c);
t_pivot	select_pivot_2(t_data *data, int size, char c);

void	sort_stack_a(t_data *data, int size, char type);
void	sort_stack_b(t_data *data, int size, char type);
void	sort_stack_quick_a(t_data *data, int size, char type);
void	sort_stack_quick_b(t_data *data, int size, char type);

void	print_optimize(t_data *data);

void	throw_error(t_data *data);

#endif