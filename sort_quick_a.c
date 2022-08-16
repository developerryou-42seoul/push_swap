/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:48:09 by sryou             #+#    #+#             */
/*   Updated: 2022/07/29 14:27:29 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_quick_a_half(t_data *data, int size)
{
	int		idx;
	int		size_b;
	int		pivot;

	idx = 0;
	size_b = 0;
	pivot = select_pivot(data, size, 'a');
	while (idx++ < size)
	{
		if (data->stack_a->front->value < pivot)
		{
			stack_operate(data, "pb");
			size_b++;
		}
		else
			stack_operate(data, "ra");
	}
	idx = 0;
	if (data->stack_a->size != size - size_b)
		while (idx++ < size - size_b)
			stack_operate(data, "rra");
	sort_stack_a(data, size - size_b, 'T');
	sort_stack_b(data, size_b, 'T');
}

void	sort_stack_quick_a_next(t_data *data, int size, \
	int size_b_top, int size_b_bottom)
{
	int	idx;

	idx = 0;
	if (data->stack_a->size != size - size_b_top - size_b_bottom)
		while (idx++ < size - size_b_top - size_b_bottom)
			stack_operate(data, "rra");
	sort_stack_a(data, size - size_b_top - size_b_bottom, 'T');
	sort_stack_b(data, size_b_top, 'T');
	sort_stack_b(data, size_b_bottom, 'B');
}

void	sort_stack_quick_a_top(t_data *data, int size)
{
	int		idx;
	int		size_b_top;
	int		size_b_bottom;
	t_pivot	pivot;

	idx = 0;
	size_b_top = 0;
	size_b_bottom = 0;
	pivot = select_pivot_2(data, size, 'a');
	while (idx++ < size)
	{
		if (data->stack_a->front->value < pivot.small)
		{
			stack_operate(data, "pb rb");
			size_b_bottom++;
		}
		else if (data->stack_a->front->value < pivot.big)
		{
			stack_operate(data, "pb");
			size_b_top++;
		}
		else
			stack_operate(data, "ra");
	}
	sort_stack_quick_a_next(data, size, size_b_top, size_b_bottom);
}

void	sort_stack_quick_a_bottom(t_data *data, int size)
{
	int	idx;

	idx = 0;
	while (idx++ < size)
		stack_operate(data, "rra");
}

void	sort_stack_quick_a(t_data *data, int size, char type)
{
	(void)type;
	if (size <= 6)
		sort_stack_quick_a_half(data, size);
	else
		sort_stack_quick_a_top(data, size);
}
