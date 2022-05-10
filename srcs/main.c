/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <gaefourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:36:43 by gaefourn          #+#    #+#             */
/*   Updated: 2022/05/10 13:21:30 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	check_all(t_lst **lst, int ac, char **av)
{
	int	i;

	i = 0;
	if (check_args(ac, av) == 1)
		return (1);
	if (init_lst(lst, ac, av) == NULL)
	{
		custom_putstr("Error\n", 2);
		return (1);
	}
	if (check_lst(lst, (*lst)->data->begin) == 1)
	{
		custom_putstr("Error\n", 2);
		return (1);
	}
	while (av[++i])
	{
		if (ft_strcmp(av[i], "2147483647") == 0
			|| ft_strcmp(av[i], "-2147483647") == 0)
		{
			custom_putstr("Error\n", 2);
			return (1);
		}
	}
	return (0);
}

/*void	print_list(t_lst *lst, char c)
{
	printf("List %c\n{\n", c);
	while (lst && lst->next)
	{
		printf("|NB : %d| POS : %d |\n", lst->data->nb, lst->data->pos);
		lst = lst->next;
	}
	printf("|NB : %d| POS : %d |\n", lst->data->nb, lst->data->pos);
	printf("}\n");
}*/

void	bad_norm(int ac, t_lst **stack_a, t_lst **stack_b)
{
	if (ac - 1 <= 3)
		algo_three(stack_a, stack_b);
	if (ac - 1 == 4)
		algo_four(stack_a, stack_b);
	if (ac - 1 == 5)
		algo_five(stack_a, stack_b);
	if (ac - 1 > 5)
		algo(stack_a, stack_b, ac - 1);
}

int	main(int ac, char **av)
{	
	t_lst	*stack_a;
	t_lst	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 2)
		return (0);
	if (check_all(&stack_a, ac, av) == 1)
		return (1);
	assign_pos(&stack_a, stack_a->data->begin);
	if (is_sorted(&stack_a, stack_a->data->begin) == 0)
	{
		free_lst(&stack_a);
		return (0);
	}
	bad_norm(ac, &stack_a, &stack_b);
	free_lst(&stack_a);
	free_lst(&stack_b);
	return (0);
}
