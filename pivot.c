/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:17:42 by sryou             #+#    #+#             */
/*   Updated: 2022/07/29 13:23:06 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
				swap(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
}

t_pivot	select_pivot_2(t_data *data, int size, char c)
{
	int		*arr;
	t_pivot	ret;

	if (c == 'a')
		arr = stack_to_array(data->stack_a, size);
	else
		arr = stack_to_array(data->stack_b, size);
	if (!arr)
		throw_error(data);
	sort_array(arr, size);
	ret.small = arr[size / 3];
	ret.big = arr[size * 2 / 3];
	free(arr);
	return (ret);
}

int	select_pivot(t_data *data, int size, char c)
{
	int	*arr;
	int	ret;

	if (c == 'a')
		arr = stack_to_array(data->stack_a, size);
	else
		arr = stack_to_array(data->stack_b, size);
	if (!arr)
		throw_error(data);
	sort_array(arr, size);
	ret = arr[size / 2];
	free(arr);
	return (ret);
}
