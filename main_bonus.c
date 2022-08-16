/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:08:36 by sryou             #+#    #+#             */
/*   Updated: 2022/07/29 16:57:55 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	read_operation(t_data *data)
{
	char	*op;

	while (1)
	{
		op = get_next_line(0);
		if (op == 0)
			break ;
		if (!is_valid_operation(op))
			throw_error(data);
		stack_operate(data, op);
		free(op);
	}
	if (is_stack_sorted(data))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
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
			read_operation(data);
		else
			throw_error(data);
		free_data(data);
	}
}
