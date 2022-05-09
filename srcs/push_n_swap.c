/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_n_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <gaefourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:57:55 by gaefourn          #+#    #+#             */
/*   Updated: 2022/05/09 11:29:19 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_lst **lst, int choice)
{
	int	nb;
	int	pos;

	if ((*lst) && (*lst)->next)
	{
		nb = (*lst)->data->nb;
		pos = (*lst)->data->pos;
		(*lst)->data->nb = (*lst)->next->data->nb;
		(*lst)->data->pos = (*lst)->next->data->pos;
		(*lst)->next->data->nb = nb;
		(*lst)->next->data->pos = pos;
	}
	printer(choice);
}

void	double_swap(t_lst **stack_a, t_lst **stack_b)
{
	if (stack_a && (*stack_a)->next)
		swap(stack_a, 69);
	if (stack_b && (*stack_b)->next)
		swap(stack_b, 69);
	printer(SS);
}

int	push_a(t_lst **stack_a, t_lst **stack_b)
{
	if (!((*stack_b)))
		return (1);
	stack_add_front(stack_b, stack_a);
	printer(PA);
	return (0);
}

int	push_b(t_lst **stack_a, t_lst **stack_b)
{
	if (!((*stack_a)))
		return (1);
	stack_add_front(stack_a, stack_b);
	printer(PB);
	return (0);
}
