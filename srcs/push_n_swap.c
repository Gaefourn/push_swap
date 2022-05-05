/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_n_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <gaefourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:57:55 by gaefourn          #+#    #+#             */
/*   Updated: 2022/05/05 15:25:08 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_lst **toSwap, t_lst **swapWith, int choice)
{
	t_struct *tmp;

	tmp = (*toSwap)->data;
	(*toSwap)->data = (*swapWith)->data;
	(*swapWith)->data = tmp;
	printer(choice);
}

void	double_swap(t_lst **stackA, t_lst** stackB)
{
	if (stackA && (*stackA)->next)
		swap(stackA, &(*stackA)->next, 69);
	if (stackB && (*stackB)->next)
		swap(stackB, &(*stackB)->next, 69);
	printer(SS);
}