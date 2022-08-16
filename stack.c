/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 08:25:21 by sryou             #+#    #+#             */
/*   Updated: 2022/08/14 13:58:47 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_stack *st, int size)
{
	t_node	*node;
	int		*arr;
	int		idx;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	idx = 0;
	node = st->front;
	while (idx < size)
	{
		arr[idx] = node->value;
		node = node->next;
		idx++;
	}
	return (arr);
}

int	stack_operate_reverse(t_data *data, char *op)
{
	int	do_op;

	if (op[1] == 'a' || (op[1] == 'r' && op[2] == '\0'))
		do_op = stack_reverse(data->stack_a);
	if (op[1] == 'b' || (op[1] == 'r' && op[2] == '\0'))
		do_op = stack_reverse(data->stack_b);
	if (op[1] == 'r' && op[2] != '\0')
	{	
		if (op[2] == 'a' || op[2] == 'r')
			do_op = stack_rereverse(data->stack_a);
		if (op[2] == 'b' || op[2] == 'r')
			do_op = stack_rereverse(data->stack_b);
	}
	return (do_op);
}

void	stack_operate_each(t_data *data, char *op)
{
	int	do_op;

	if (op[0] == 's')
	{
		if (op[1] == 'a' || op[1] == 's')
			do_op = stack_switch(data->stack_a);
		if (op[1] == 'b' || op[1] == 's')
			do_op = stack_switch(data->stack_b);
	}
	if (op[0] == 'p')
	{
		if (op[1] == 'a')
			do_op = stack_move(data->stack_a, data->stack_b);
		if (op[1] == 'b')
			do_op = stack_move(data->stack_b, data->stack_a);
	}
	if (op[0] == 'r')
		do_op = stack_operate_reverse(data, op);
	if (do_op)
		ft_lstadd_back(&(data->operation), ft_lstnew(op));
	else
		free(op);
}

void	stack_operate(t_data *data, char *op)
{
	int		idx;
	char	**strs;

	strs = ft_split(op, ' ');
	if (strs == 0)
		throw_error(data);
	idx = 0;
	while (strs[idx] != 0)
	{
		stack_operate_each(data, strs[idx]);
		idx++;
	}
	free(strs);
}
