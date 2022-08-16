/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:48:09 by sryou             #+#    #+#             */
/*   Updated: 2022/07/29 14:37:45 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_quick_b_half(t_data *data, int size)
{
	int		idx;
	int		size_a;
	int		pivot;

	idx = 0;
	size_a = 0;
	pivot = select_pivot(data, size, 'b');
	while (idx++ < size)
	{
		if (data->stack_b->front->value >= pivot)
		{
			stack_operate(data, "pa");
			size_a++;
		}
		else
			stack_operate(data, "rb");
	}
	idx = 0;
	if (data->stack_b->size != size - size_a)
		while (idx++ < size - size_a)
			stack_operate(data, "rrb");
	sort_stack_a(data, size_a, 'T');
	sort_stack_b(data, size - size_a, 'T');
}

void	sort_stack_quick_b_next(t_data *data, int size, \
	int size_a_top, int size_a_bottom)
{
	int	idx;

	idx = 0;
	if (data->stack_b->size != size - size_a_top - size_a_bottom)
		while (idx++ < size - size_a_top - size_a_bottom)
			stack_operate(data, "rrb");
	sort_stack_a(data, size_a_top, 'T');
	sort_stack_a(data, size_a_bottom, 'B');
	sort_stack_b(data, size - size_a_top - size_a_bottom, 'T');
}

void	sort_stack_quick_b_top(t_data *data, int size)
{
	int		idx;
	int		size_a_top;
	int		size_a_bottom;
	t_pivot	pivot;

	idx = 0;
	size_a_top = 0;
	size_a_bottom = 0;
	pivot = select_pivot_2(data, size, 'b');
	while (idx++ < size)
	{
		if (data->stack_b->front->value >= pivot.big)
		{
			stack_operate(data, "pa");
			size_a_top++;
		}
		else if (data->stack_b->front->value >= pivot.small)
		{
			stack_operate(data, "pa ra");
			size_a_bottom++;
		}
		else
			stack_operate(data, "rb");
	}
	sort_stack_quick_b_next(data, size, size_a_top, size_a_bottom);
}

void	sort_stack_quick_b_bottom(t_data *data, int size)
{
	int	idx;

	idx = 0;
	while (idx++ < size)
		stack_operate(data, "rrb");
}

void	sort_stack_quick_b(t_data *data, int size, char type)
{
	(void)type;
	if (size <= 6)
		sort_stack_quick_b_half(data, size);
	else
		sort_stack_quick_b_top(data, size);
}
