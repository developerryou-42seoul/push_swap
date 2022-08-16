/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 23:39:45 by sryou             #+#    #+#             */
/*   Updated: 2022/07/27 16:37:16 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (len == 10 && minus == 0 && ft_strncmp(str, "2147483647", 10) > 0)
		return (0);
	if (len == 10 && minus == 1 && ft_strncmp(str, "2147483648", 10) > 0)
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
