/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <gaefourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:01:23 by gaefourn          #+#    #+#             */
/*   Updated: 2022/05/10 15:10:07 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	custom_putstr(char *str, int sortie)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	write(sortie, str, i);
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	nb;
	int	i;
	int	neg;

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

int	ft_isdigit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] == '+' || str[i] == '-') && i == 0)
			continue ;
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 2)
		return (1);
	while (++i != ac)
	{
		if (ft_isdigit(av[i]) == 0)
		{
			custom_putstr("Error\n", 2);
			return (1);
		}
	}
	return (0);
}

void	free_lst(t_lst **lst)
{
	t_lst	*tmp;

	while ((*lst))
	{
		if ((*lst)->data)
			free((*lst)->data);
		tmp = (*lst)->next;
		free((*lst));
		(*lst) = tmp;
	}
}
