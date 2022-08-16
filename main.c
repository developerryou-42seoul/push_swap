/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:08:36 by sryou             #+#    #+#             */
/*   Updated: 2022/07/29 15:27:41 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_stack(t_data *data, char *str)
{
	int		idx;
	char	**strs;

	strs = ft_split(str, ' ');
	if (strs == 0)
		throw_error(data);
	idx = 0;
	while (strs[idx] != 0)
	{
		if (is_valid_int(strs[idx]))
			stack_push_back(data->stack_a, ft_atoi(strs[idx]));
		else
			throw_error(data);
		free(strs[idx]);
		idx++;
	}
	free(strs);
}

int	main(int argc, char **argv)
{
	int		idx;
	t_data	*data;

	if (argc > 1)
	{
		idx = 1;
		data = init_data();
		if (!data)
			throw_error(data);
		while (idx < argc)
		{
			make_stack(data, argv[idx]);
			idx++;
		}
		if (is_valid_stack(data->stack_a))
			sort_stack_a(data, data->stack_a->size, 'T');
		else
			throw_error(data);
		print_optimize(data);
		free_data(data);
	}
}
