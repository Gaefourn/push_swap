/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_n_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <gaefourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:57:55 by gaefourn          #+#    #+#             */
/*   Updated: 2022/05/07 18:12:33 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_lst **toSwap, t_lst **swapWith, int choice)
{
	t_struct	*tmp;

	if (!(*toSwap) || !(*swapWith))
		return ;
	tmp = (*toSwap)->data;
	(*toSwap)->data = (*swapWith)->data;
	(*swapWith)->data = tmp;
	printer(choice);
}

void	double_swap(t_lst **stack_a, t_lst **stack_b)
{
	if (stack_a && (*stack_a)->next)
		swap(stack_a, &(*stack_a)->next, 69);
	if (stack_b && (*stack_b)->next)
		swap(stack_b, &(*stack_b)->next, 69);
	printer(SS);
}

int	push_a(t_lst **stack_a, t_lst **stack_b)
{
	if (!((*stack_b)))
		return (1);
	stack_add_front(stack_a, stack_b);
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
