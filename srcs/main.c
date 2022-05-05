/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <gaefourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:36:43 by gaefourn          #+#    #+#             */
/*   Updated: 2022/05/05 14:01:40 by gaefourn         ###   ########.fr       */
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
	lst = head;
	if (check_lst(&lst) == 1)
	{
		custom_putstr("Error, duplicate number.\n", 2);
		return (1);
	}
	free_lst(&lst);
	return (0);
}
