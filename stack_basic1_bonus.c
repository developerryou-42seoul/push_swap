/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_basic1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:53:17 by sryou             #+#    #+#             */
/*   Updated: 2022/07/29 15:31:07 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_node	*stack_newnode(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == 0)
		return (0);
	node->value = value;
	node->next = 0;
	node->prev = 0;
	return (node);
}

void	stack_push_back(t_stack *st, int value)
{
	t_node	*temp;

	if (st == 0)
		return ;
	temp = stack_newnode(value);
	st->size++;
	if (st->front == 0)
	{	
		st->front = temp;
		st->back = temp;
	}
	else
	{
		temp->prev = st->back;
		st->back->next = temp;
		st->back = temp;
	}
}

void	stack_push_front(t_stack *st, int value)
{
	t_node	*temp;

	if (st == 0)
		return ;
	temp = stack_newnode(value);
	st->size++;
	if (st->front == 0)
	{	
		st->front = temp;
		st->back = temp;
	}
	else
	{
		temp->next = st->front;
		st->front->prev = temp;
		st->front = temp;
	}
}

int	stack_pop_back(t_stack *st)
{
	int		ret;
	t_node	*temp;

	ret = st->back->value;
	temp = st->back;
	st->back = temp->prev;
	stack_delnode(temp);
	st->size--;
	return (ret);
}

int	stack_pop_front(t_stack *st)
{
	int		ret;
	t_node	*temp;

	ret = st->front->value;
	temp = st->front;
	st->front = temp->next;
	stack_delnode(temp);
	st->size--;
	return (ret);
}
