/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <gaefourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:36:43 by gaefourn          #+#    #+#             */
/*   Updated: 2022/05/16 11:33:49 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	long	nb;
	int		i;
	int		neg;

	i = 0;
	nb = 0;
	neg = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\r'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg = 1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = ((nb * 10) + (nptr[i] - 48));
		i++;
	}
	if (neg > 0)
		return (-nb);
	return (nb);
}

int	check_all(t_lst **lst, int ac, char **av)
{
	int	i;

	i = 0;
	if (check_args(ac, av) == 1 || init_lst(lst, ac, av) == NULL
		|| check_lst(lst, (*lst)->data->begin) == 1)
	{
		custom_putstr("Error\n", 2);
		return (1);
	}
	while (av[++i])
	{
		if (ft_strlen(av[i]) >= 10)
		{
			if ((ft_atol(av[i]) > 2147483647 || ft_atol(av[i]) < -2147483648)
				|| ft_atol(av[i]) == -1)
			{
				custom_putstr("Error\n", 2);
				return (1);
			}
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
	if (ac <= 2)
		return (0);
	if (check_all(&stack_a, ac, av) == 1)
	{
		free_lst(&stack_a);
		free_lst(&stack_b);
		return (1);
	}
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
