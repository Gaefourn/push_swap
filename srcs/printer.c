/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <gaefourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:24:59 by gaefourn          #+#    #+#             */
/*   Updated: 2022/05/10 09:30:08 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	printer(int nb)
{
	if (nb == 0)
		custom_putstr("sa\n", 1);
	if (nb == 1)
		custom_putstr("sb\n", 1);
	if (nb == 2)
		custom_putstr("ss\n", 1);
	if (nb == 3)
		custom_putstr("pa\n", 1);
	if (nb == 4)
		custom_putstr("pb\n", 1);
	if (nb == 5)
		custom_putstr("ra\n", 1);
	if (nb == 6)
		custom_putstr("rb\n", 1);
	if (nb == 7)
		custom_putstr("rr\n", 1);
	if (nb == 8)
		custom_putstr("rra\n", 1);
	if (nb == 9)
		custom_putstr("rrb\n", 1);
	if (nb == 10)
		custom_putstr("rrr\n", 1);
	else
		return ;
}
