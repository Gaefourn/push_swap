/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <gaefourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:10:31 by gaefourn          #+#    #+#             */
/*   Updated: 2022/05/05 13:03:37 by gaefourn         ###   ########.fr       */
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
	(*lst)->data->size = ac - 1;
	(*lst)->data->nb = ft_atoi(av[1]);
	head = (*lst);
	while (++i != ac)
	{
		(*lst)->next = new_link(i, ac, head, av);
		(*lst) = (*lst)->next;
		if (!(*lst))
			return (NULL);
	}
	(*lst) = head;
	return ("Ok");
}

t_lst	*new_link(int i, int size, t_lst *head, char **av)
{
	t_lst	*tmp;

	tmp = malloc(sizeof(t_lst));
	if (!(tmp))
		return (NULL);
	tmp->data = malloc(sizeof(t_struct));
	if (!(tmp))
		return (NULL);
	tmp->data->size = size;
	tmp->data->begin = head;
	tmp->data->nb = ft_atoi(av[i]);
	tmp->next = NULL;
	return (tmp);
}
