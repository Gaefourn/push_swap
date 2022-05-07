/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <gaefourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:36:43 by gaefourn          #+#    #+#             */
/*   Updated: 2022/05/07 20:13:47 by gaefourn         ###   ########.fr       */
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

void	print_list(t_lst *lst, char c)
{
	printf("List %c\n{\n", c);
	while (lst && lst->next)
	{
		printf("__________\n");
		printf("|NB : %d  |\n", lst->data->nb);
		lst = lst->next;
	}
	printf("__________\n");
	printf("|NB : %d  |\n", lst->data->nb);
	printf("__________\n");
	printf("}\n");
}

int	main(int ac, char **av)
{	
	t_lst	*stack_a;
	t_lst	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (check_all(&stack_a, ac, av) == 1)
		return (1);
	free_lst(&stack_a);
	free_lst(&stack_b);
	return (0);
}
