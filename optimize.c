/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:23:38 by sryou             #+#    #+#             */
/*   Updated: 2022/07/29 14:57:42 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_operation(t_list *operation)
{
	while (operation != 0)
	{
		ft_putendl_fd(operation->content, 1);
		operation = operation->next;
	}
}

int	reduce_all(char *op1, char *op2)
{
	if (op1[0] == 'r' && op2[0] == 'r' && op1[1] != 'r' && \
	op2[1] == 'r' && op1[1] == op2[2])
		return (1);
	if (op1[0] == 'r' && op2[0] == 'r' && op1[1] == 'r' && \
	op2[1] != 'r' && op1[2] == op2[1])
		return (1);
	if (op1[0] == 'p' && op2[0] == 'p' && op1[1] != op2[1])
		return (1);
	return (0);
}

int	reduce_one(char *op1, char *op2)
{
	if (op1[0] == 'p' || op2[0] == 'p')
		return (0);
	if (op1[0] == 's' && op2[0] == 's' && op1[1] + op2[1] == 'a' + 'b')
	{
		op2[1] = 's';
		return (1);
	}
	if (op1[0] == 'r' && op2[0] == 'r' && op1[1] + op2[1] == 'a' + 'b')
	{
		op2[1] = 'r';
		return (1);
	}
	if (op1[0] == 'r' && op2[0] == 'r' && op1[1] == 'r' && op2[1] == 'r' && \
		op1[2] + op2[2] == 'a' + 'b')
	{
		op2[2] = 'r';
		return (1);
	}
	return (0);
}

int	optimize(t_list *op)
{
	t_list	*temp;

	if (reduce_all(op->next->content, op->next->next->content))
	{
		temp = op->next->next->next;
		ft_lstdelone(op->next, free);
		ft_lstdelone(op->next->next, free);
		op->next = temp;
		return (1);
	}
	if (reduce_one(op->next->content, op->next->next->content))
	{
		temp = op->next->next;
		ft_lstdelone(op->next, free);
		op->next = temp;
		return (1);
	}
	return (0);
}

void	print_optimize(t_data *data)
{
	t_list	*op;
	int		flag;

	flag = 1;
	while (flag)
	{
		flag = 0;
		op = data->operation;
		while (op != 0 && op->next != 0 && op->next->next != 0)
		{
			if (optimize(op))
				flag = 1;
			op = op->next;
		}
	}
	print_operation(data->operation);
}
