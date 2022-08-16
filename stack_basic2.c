/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_basic2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:54:44 by sryou             #+#    #+#             */
/*   Updated: 2022/07/25 16:14:11 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_delnode(t_node *node)
{
	if (node == 0)
		return ;
	if (node->prev != 0)
		node->prev->next = node->next;
	if (node->next != 0)
		node->next->prev = node->prev;
	free(node);
}

void	stack_clear(t_stack *st)
{
	t_node	*node;
	t_node	*temp;

	if (st == 0)
		return ;
	node = st->front;
	while (node)
	{
		temp = node->next;
		stack_delnode(node);
		node = temp;
	}
	st->front = 0;
	st->back = 0;
	st->size = 0;
}
