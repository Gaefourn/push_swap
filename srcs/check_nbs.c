/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nbs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <gaefourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:10:21 by gaefourn          #+#    #+#             */
/*   Updated: 2022/05/10 12:38:06 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_pos(t_lst *head, int nb, t_lst **which)
{
	int	i;

	i = 0;
	while (head)
	{
		if (head->data->nb == (*which)->data->nb)
			;
		else if (head->data->nb < nb)
			i++;
		head = head->next;
	}
	(*which)->data->pos = i;
}

void	assign_pos(t_lst **stack, t_lst *head)
{
	while ((*stack))
	{
		check_pos(head, (*stack)->data->nb, stack);
		(*stack) = (*stack)->next;
	}
	(*stack) = head;
}

void	algo_four(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*head;

	if (is_sorted(stack_a, (*stack_a)->data->begin) == 0)
		return ;
	while (*stack_a)
	{
		if ((*stack_a)->data->pos == 3)
		{
			push_b(stack_a, stack_b);
			head = (*stack_a)->data->begin;
			break ;
		}
		else
		{
			rotate(stack_a, RA);	
			head = (*stack_a)->data->begin;
		}
	}
	*stack_a = head;
	algo_three(stack_a, stack_b);
	push_a(stack_a, stack_b);
	rotate(stack_a, RA);
}