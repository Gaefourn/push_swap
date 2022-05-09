/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <gaefourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:50:31 by gaefourn          #+#    #+#             */
/*   Updated: 2022/05/09 10:03:40 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo(t_lst **stack_a, t_lst **stack_b, int size)
{
	int	max_num;
	int	max_bits;
	int	i;
	int	j;
	int	num;

	i = -1;
	max_num = size - 1;
	max_bits = 0;
	while (max_num >> max_bits != 0)
		++max_bits;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			num = (*stack_a)->data->pos;
			if (((num >> i) & 1) == 1)
				rotate(stack_a, RA);
			else
				push_b(stack_a, stack_b);
		}
		while (push_a(stack_a, stack_b) == 0)
			;
	}
}

void	algo_three(t_lst **stack_a, t_lst **stack_b)
{
	if ((*stack_a)->data->pos == 0 && (*stack_a)->next->data->pos == 1)
		return ;
	if ((*stack_a)->data->pos == 0 && (*stack_a)->next->data->pos == 2)
	{
		push_b(stack_a, stack_b);
		rotate(stack_a, RA);
		push_a(stack_a, stack_b);
	}
	if ((*stack_a)->data->pos == 1 && (*stack_a)->next->data->pos == 2)
		reverse_rotate(stack_a, RRA);
	if ((*stack_a)->data->pos == 2 && (*stack_a)->next->data->pos == 1)
	{
		rotate(stack_a, RA);
		swap(stack_a, SA);
	}
	
}
