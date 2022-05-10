/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <gaefourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:18:12 by gaefourn          #+#    #+#             */
/*   Updated: 2022/05/10 15:37:16 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_lst **lst, int choice)
{
	t_lst	*tmp;
	t_lst	*head;

	if ((*lst) == NULL)
		return ;
	head = (*lst)->next;
	tmp = (*lst);
	if (!head)
		return ;
	while ((*lst) && (*lst)->next)
	{
		(*lst)->data->begin = head;
		(*lst) = (*lst)->next;
	}
	(*lst)->next = tmp;
	(*lst) = (*lst)->next;
	(*lst)->next = NULL;
	(*lst) = head;
	printer(choice);
}

void	reverse_rotate(t_lst **lst, int choice)
{
	t_lst	*tmp;
	t_lst	*head;

	if (!(*lst) || ((*lst) && !(*lst)->next))
		return ;
	tmp = (*lst)->data->begin;
	while ((*lst) && (*lst)->next)
		(*lst) = (*lst)->next;
	head = (*lst);
	(*lst) = tmp;
	while ((*lst) && (*lst)->next)
	{
		(*lst)->data->begin = head;
		if ((*lst)->next && !(*lst)->next->next)
			break ;
		(*lst) = (*lst)->next;
	}
	(*lst)->next = NULL;
	(*lst)->data->begin = head;
	(*lst) = head;
	(*lst)->next = tmp;
	printer(choice);
}

void	double_rotate(t_lst **stack_a, t_lst **stack_b)
{
	rotate(stack_a, 69);
	rotate(stack_b, 69);
	printer(RR);
}

void	double_reverse_rotate(t_lst **stack_a, t_lst **stack_b)
{
	reverse_rotate(stack_a, 69);
	reverse_rotate(stack_b, 69);
	printer(RR);
}

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}
