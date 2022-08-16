/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:09:06 by sryou             #+#    #+#             */
/*   Updated: 2022/07/29 14:13:31 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_switch(t_stack *st)
{
	int	temp;

	if (st->size >= 2)
	{
		temp = st->front->value;
		st->front->value = st->front->next->value;
		st->front->next->value = temp;
		return (1);
	}
	return (0);
}

int	stack_move(t_stack *st_dest, t_stack *st_src)
{
	int	temp;

	if (st_src->size >= 1)
	{
		temp = stack_pop_front(st_src);
		stack_push_front(st_dest, temp);
		return (1);
	}
	return (0);
}

int	stack_reverse(t_stack *st)
{
	int	temp;

	if (st->size >= 2)
	{
		temp = stack_pop_front(st);
		stack_push_back(st, temp);
		return (1);
	}
	return (0);
}

int	stack_rereverse(t_stack *st)
{
	int	temp;

	if (st->size >= 2)
	{
		temp = stack_pop_back(st);
		stack_push_front(st, temp);
		return (1);
	}
	return (0);
}
