/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <gaefourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:36:43 by gaefourn          #+#    #+#             */
/*   Updated: 2022/05/05 12:52:48 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{	
	t_lst	*lst;
	t_lst	*head;

	lst = NULL;
	if (check_args(ac, av) == 1)
		return (1);
	if (init_lst(&lst, ac, av) == NULL)
	{
		custom_putstr("Malloc error\n", 2);
		return (1);
	}
	head = lst->data->begin;
	while (lst && lst->next != NULL)
	{
		printf("%d\n", lst->data->nb);
		lst = lst->next;
	}
	printf("%d\n", lst->data->nb);
	lst = head;
	free_lst(&lst);
	/* MUST CHECK DUPLICATES */
	return (0);
}
