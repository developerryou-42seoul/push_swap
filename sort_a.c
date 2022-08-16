/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 08:31:06 by sryou             #+#    #+#             */
/*   Updated: 2022/07/29 15:00:02 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_a2(t_data *data)
{
	if (data->stack_a->front->value > data->stack_a->front->next->value)
		stack_operate(data, "sa");
}

void	sort_stack_a3_compact(t_data *data)
{
	int	first;
	int	second;
	int	third;

	first = data->stack_a->front->value;
	second = data->stack_a->front->next->value;
	third = data->stack_a->back->value;
	if (first < third && third < second)
		stack_operate(data, "sa ra");
	if (second < third && third < first)
		stack_operate(data, "ra");
	if (second < first && first < third)
		stack_operate(data, "sa");
	if (third < first && first < second)
		stack_operate(data, "rra");
	if (third < second && second < first)
		stack_operate(data, "sa rra");
}

void	sort_stack_a3(t_data *data)
{
	int	first;
	int	second;
	int	third;

	first = data->stack_a->front->value;
	second = data->stack_a->front->next->value;
	third = data->stack_a->front->next->next->value;
	if (first < third && third < second)
		stack_operate(data, "ra sa rra");
	if (second < third && third < first)
		stack_operate(data, "sa ra sa rra");
	if (second < first && first < third)
		stack_operate(data, "sa");
	if (third < first && first < second)
		stack_operate(data, "ra sa rra sa");
	if (third < second && second < first)
		stack_operate(data, "sa ra sa rra sa");
}

void	sort_stack_a(t_data *data, int size, char type)
{
	int	idx;

	idx = 0;
	if (type == 'B')
		while (idx++ < size)
			stack_operate(data, "rra");
	if (size == 2)
		sort_stack_a2(data);
	else if (size == 3 && data->stack_a->size == size)
		sort_stack_a3_compact(data);
	else if (size == 3 && data->stack_a->size != size)
		sort_stack_a3(data);
	else if (size > 3)
		sort_stack_quick_a(data, size, type);
}
