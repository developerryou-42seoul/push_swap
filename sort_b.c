/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:31:30 by sryou             #+#    #+#             */
/*   Updated: 2022/07/29 14:27:16 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_b2(t_data *data)
{
	if (data->stack_b->front->value < data->stack_b->front->next->value)
		stack_operate(data, "sb");
	stack_operate(data, "pa pa");
}

void	sort_stack_b3(t_data *data)
{
	int	first;
	int	second;
	int	third;

	first = data->stack_b->front->value;
	second = data->stack_b->front->next->value;
	third = data->stack_b->front->next->next->value;
	if (first > third && third > second)
		stack_operate(data, "rb sb rrb");
	if (second > third && third > first)
		stack_operate(data, "sb rb sb rrb");
	if (second > first && first > third)
		stack_operate(data, "sb");
	if (third > first && first > second)
		stack_operate(data, "rb sb rrb sb");
	if (third > second && second > first)
		stack_operate(data, "sb rb sb rrb sb");
	stack_operate(data, "pa pa pa");
}

void	sort_stack_b(t_data *data, int size, char type)
{
	int	idx;

	idx = 0;
	if (type == 'B')
		while (idx++ < size)
			stack_operate(data, "rrb");
	if (size == 1)
		stack_operate(data, "pa");
	if (size == 2)
		sort_stack_b2(data);
	else if (size == 3)
		sort_stack_b3(data);
	else if (size > 3)
		sort_stack_quick_b(data, size, type);
}
