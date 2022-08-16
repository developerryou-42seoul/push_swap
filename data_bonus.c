/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 23:17:38 by sryou             #+#    #+#             */
/*   Updated: 2022/07/29 15:29:14 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->stack_a = malloc(sizeof(t_stack));
	data->stack_b = malloc(sizeof(t_stack));
	data->operation = 0;
	if (data->stack_a == 0 || data->stack_b == 0)
		return (NULL);
	return (data);
}

void	free_data(t_data *data)
{
	if (!data)
	{
		if (!(data->stack_a))
		{
			stack_clear(data->stack_a);
			free(data->stack_a);
		}
		if (!(data->stack_b))
		{
			stack_clear(data->stack_b);
			free(data->stack_b);
		}
		if (!(data->operation))
		{
			ft_lstclear(&(data->operation), free);
			free(data->operation);
		}
		free(data);
	}
}
