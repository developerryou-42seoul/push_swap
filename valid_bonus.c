/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 23:39:45 by sryou             #+#    #+#             */
/*   Updated: 2022/07/29 17:10:58 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_valid_int(char *str)
{
	int	len;
	int	minus;

	minus = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = 1;
		str++;
	}
	len = 0;
	while (str[len])
	{
		if (!ft_isdigit(str[len]))
			return (0);
		len++;
	}
	if (len > 10)
		return (0);
	if (len == 10 && minus == 0 && ft_strncmp(str, "2147483647", 11) > 0)
		return (0);
	if (len == 10 && minus == 1 && ft_strncmp(str, "2147483648", 11) > 0)
		return (0);
	return (1);
}

int	is_valid_stack(t_stack *st)
{
	int	*arr;
	int	i;
	int	j;
	int	flag;

	arr = stack_to_array(st, st->size);
	if (!arr)
		return (0);
	flag = 1;
	i = 0;
	while (i < st->size)
	{
		j = i + 1;
		while (j < st->size)
			if (arr[i] == arr[j++])
				flag = 0;
		i++;
	}
	free(arr);
	return (flag);
}

int	is_valid_operation(char *op)
{
	if (ft_strncmp(op, "pa\n", 3) == 0 || ft_strncmp(op, "pb\n", 3) == 0)
	{
		op[2] = '\0';
		return (1);
	}
	if (ft_strncmp(op, "sa\n", 3) == 0 || ft_strncmp(op, "sb\n", 3) == 0 || \
		ft_strncmp(op, "ss\n", 3) == 0)
	{
		op[2] = '\0';
		return (1);
	}
	if (ft_strncmp(op, "ra\n", 3) == 0 || ft_strncmp(op, "rb\n", 3) == 0 || \
		ft_strncmp(op, "rr\n", 3) == 0)
	{
		op[2] = '\0';
		return (1);
	}
	if (ft_strncmp(op, "rra\n", 4) == 0 || ft_strncmp(op, "rrb\n", 4) == 0 || \
		ft_strncmp(op, "rrr\n", 4) == 0)
	{
		op[3] = '\0';
		return (1);
	}
	return (0);
}

int	is_stack_sorted(t_data *data)
{
	int	*arr;
	int	ret;
	int	idx;

	if (data->stack_b->size != 0)
		return (0);
	arr = stack_to_array(data->stack_a, data->stack_a->size);
	if (!arr)
		return (0);
	idx = 0;
	ret = 1;
	while (idx < data->stack_a->size - 1)
	{
		if (arr[idx] > arr[idx + 1])
			ret = 0;
		idx++;
	}
	free(arr);
	return (ret);
}
