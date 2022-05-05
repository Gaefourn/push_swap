/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <gaefourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:36:43 by gaefourn          #+#    #+#             */
/*   Updated: 2022/05/05 15:10:52 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_all(t_lst **lst, int ac, char **av)
{
	if (check_args(ac, av) == 1)
		return (1);
	if (init_lst(lst, ac, av) == NULL)
	{
		custom_putstr("Malloc error\n", 2);
		return (1);
	}
	if (check_lst(lst, (*lst)->data->begin) == 1)
	{
		custom_putstr("Error, duplicate number.\n", 2);
		return (1);
	}
	return (0);
}

void	print_list(t_lst *lst)
{
	while (lst && lst->next)
	{
		printf("%d\n", lst->data->nb);
		lst = lst->next;
	}
	printf("%d\n", lst->data->nb);
}

int	main(int ac, char **av)
{	
	t_lst	*stackA;
	t_lst	*stackB;

	stackA = NULL;
	stackB = NULL;
	if (check_all(&stackA, ac, av) == 1)
		return (1);
	print_list(stackA); // remove this
	free_lst(&stackA);
	return (0);
}
