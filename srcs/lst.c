/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <gaefourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:10:31 by gaefourn          #+#    #+#             */
/*   Updated: 2022/05/10 14:57:30 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*init_lst(t_lst **lst, int ac, char **av)
{
	int		i;
	t_lst	*head;

	i = 1;
	(*lst) = malloc(sizeof(t_lst));
	if (!(*lst))
		return (NULL);
	(*lst)->data = malloc(sizeof(t_struct));
	if (!(*lst)->data)
		return (NULL);
	(*lst)->next = NULL;
	(*lst)->data->begin = (*lst);
	(*lst)->data->nb = ft_atoi(av[1]);
	head = (*lst);
	while (++i != ac)
	{
		(*lst)->next = new_link(i, head, av);
		(*lst) = (*lst)->next;
		if (!(*lst))
			return (NULL);
	}
	(*lst) = head;
	return ("Ok");
}

t_lst	*new_link(int i, t_lst *head, char **av)
{
	t_lst	*tmp;

	tmp = malloc(sizeof(t_lst));
	if (!(tmp))
		return (NULL);
	tmp->data = malloc(sizeof(t_struct));
	if (!(tmp))
		return (NULL);
	tmp->data->begin = head;
	tmp->data->nb = ft_atoi(av[i]);
	tmp->next = NULL;
	return (tmp);
}

int	find_one(int tofind, t_lst *lst)
{
	while (lst && lst->next)
	{
		if (tofind == lst->data->nb)
			return (1);
		lst = lst->next;
	}
	if (lst)
		if (tofind == lst->data->nb)
			return (1);
	return (0);
}

int	check_lst(t_lst **lst, t_lst *head)
{
	int	tofind;

	while ((*lst) && (*lst)->next)
	{
		tofind = (*lst)->data->nb;
		if (find_one(tofind, (*lst)->next) == 1)
		{
			(*lst) = head;
			return (1);
		}
		(*lst) = (*lst)->next;
	}
	if (find_one(tofind, (*lst)) == 1)
	{
		(*lst) = head;
		return (1);
	}
	(*lst) = head;
	return (0);
}

int	is_sorted(t_lst **lst, t_lst *head)
{
	while (*lst)
	{
		if ((*lst)->next && *lst && (*lst)->data->pos > (*lst)->next->data->pos)
		{
			*lst = head;
			return (1);
		}
		*lst = (*lst)->next;
	}
	*lst = head;
	return (0);
}
