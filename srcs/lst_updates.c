/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_updates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <gaefourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 12:53:43 by gaefourn          #+#    #+#             */
/*   Updated: 2022/05/09 09:27:57 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sad_norm(t_lst **to, t_lst *tmp)
{
	while ((*to))
	{
		(*to)->data->begin = tmp;
		(*to) = (*to)->next;
	}
	(*to) = tmp;
}

void	stack_add_front(t_lst **from, t_lst **to)
{
	t_lst	*tmp;

	tmp = (*from)->data->begin;
	if (tmp == NULL)
		tmp = (*from);
	if (!(*to))
	{
		update_stack(from);
		tmp->next = NULL;
		(*to) = tmp;
		return ;
	}
	else if ((*to) && !(*to)->next)
	{
		update_stack(from);
		tmp->next = (*to);
		(*to)->data->begin = tmp;
		(*to) = tmp;
	}
	else
	{
		update_stack(from);
		tmp->next = (*to);
		sad_norm(to, tmp);
	}
}

void	update_stack(t_lst **stack)
{
	t_lst	*head;

	head = (*stack)->next;
	while ((*stack) && (*stack)->next)
	{
		(*stack) = (*stack)->next;
		(*stack)->data->begin = head;
	}
	(*stack)->data->begin = head;
	(*stack) = head;
}
