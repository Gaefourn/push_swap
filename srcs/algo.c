/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <gaefourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:50:31 by gaefourn          #+#    #+#             */
/*   Updated: 2022/05/10 11:57:57 by gaefourn         ###   ########.fr       */
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
	if ((*stack_a)->data->pos == 2 && (*stack_a)->next->data->pos == 0)
		rotate(stack_a, RA);
}

void	shlag(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*tmp;
	t_lst	*tmp2;

	tmp2 = malloc(sizeof(t_lst));
	tmp2->data = malloc(sizeof(t_struct));
	tmp2->data->nb = (*stack_b)->next->data->nb;
	tmp2->data->pos = (*stack_b)->next->data->pos;
	tmp2->data->begin = tmp2;
	tmp = malloc(sizeof(t_lst));
	tmp->data = malloc(sizeof(t_struct));
	tmp->data->nb = (*stack_b)->data->nb;
	tmp->data->pos = (*stack_b)->data->pos;
	tmp->data->begin = tmp2;
	tmp2->next = tmp;
	tmp->next = *stack_a;
	while (*stack_a)
	{
		(*stack_a)->data->begin = tmp2;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = tmp2;
	printer(PA);
	printer(PA);
}

void	norm(t_lst **stack_a, t_lst *head)
{
	while ((*stack_a))
	{
		if ((*stack_a)->data->pos == 2)
			(*stack_a)->data->pos = 0;
		if ((*stack_a)->data->pos == 3)
			(*stack_a)->data->pos = 1;
		if ((*stack_a)->data->pos == 4)
			(*stack_a)->data->pos = 2;
		(*stack_a) = (*stack_a)->next;
	}
	(*stack_a) = head;
}

void	algo_five(t_lst **stack_a, t_lst **stack_b)
{
	int		i;
	t_lst	*head;

	i = 0;
	if (is_sorted(stack_a, (*stack_a)->data->begin) == 0)
		return ;
	while ((*stack_a) && (*stack_a)->next)
	{
		if ((*stack_a)->data->pos == 0 || ((*stack_a)->data->pos == 1))
			push_b(stack_a, stack_b);
		else
			rotate(stack_a, RA);
		if (i == 4)
			break ;
		i++;
	}
	(*stack_a) = (*stack_a)->data->begin;
	if ((*stack_b)->data->pos == 0)
		rotate(stack_b, RB);
	head = (*stack_a);
	norm(stack_a, head);
	algo_three(stack_a, stack_b);
	shlag(stack_a, stack_b);
}
