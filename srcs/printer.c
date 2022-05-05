/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <gaefourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:24:59 by gaefourn          #+#    #+#             */
/*   Updated: 2022/05/05 15:24:17 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	printer(int nb)
{
	if (nb == 0)
		custom_putstr("Swap A.\n", 1);
	if (nb == 1)
		custom_putstr("Swap B.\n", 1);
	if (nb == 2)
		custom_putstr("Swap A and B.\n", 1);
	if (nb == 3)
		custom_putstr("Push A.\n", 1);
	if (nb == 4)
		custom_putstr("Push B.\n", 1);
	if (nb == 5)
		custom_putstr("Rotate A.\n", 1);
	if (nb == 6)
		custom_putstr("Rotate B.\n", 1);
	if (nb == 7)
		custom_putstr("Rotate A and B.\n", 1);
	if (nb == 8)
		custom_putstr("Reverse rotate A.\n", 1);
	if (nb == 9)
		custom_putstr("Reverse rotate B.\n", 1);
	if (nb == 10)
		custom_putstr("Reverse rotate A and B.\n", 1);
	else
		return ;
}
