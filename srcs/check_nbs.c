/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nbs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <gaefourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:10:21 by gaefourn          #+#    #+#             */
/*   Updated: 2022/05/08 18:33:17 by gaefourn         ###   ########.fr       */
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
