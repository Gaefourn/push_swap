/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <gaefourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:48:06 by gaefourn          #+#    #+#             */
/*   Updated: 2022/05/10 15:19:51 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_struct
{
	int				nb;
	int				pos;
	struct s_lst	*begin;
}				t_struct;

typedef struct s_lst
{
	t_struct		*data;
	struct s_lst	*next;
}				t_lst;

int		custom_putstr(char *str, int sortie);
int		ft_atoi(const char *nptr);
int		check_args(int ac, char **av);
void	printer(int nb);
int		ft_isdigit(char *str);
char	*init_lst(t_lst **lst, int ac, char **av);
t_lst	*new_link(int i, t_lst *head, char **av);
void	free_lst(t_lst **lst);
int		check_lst(t_lst **lst, t_lst *head);
void	swap(t_lst **toSwap, int choice);
void	double_swap(t_lst **stackA, t_lst **stackB);
int		push_a(t_lst **stackA, t_lst **stackB);
int		push_b(t_lst **stackA, t_lst **stackB);
void	stack_add_front(t_lst **from, t_lst **to);
void	update_stack(t_lst **stack);
void	rotate(t_lst **lst, int choice);
void	reverse_rotate(t_lst **lst, int choice);
void	assign_pos(t_lst **stack, t_lst *head);
void	check_pos(t_lst *head, int nb, t_lst **which);
void	algo(t_lst **stack_a, t_lst **stack_b, int size);
void	print_list(t_lst *lst, char c);
void	algo_three(t_lst **stack_a, t_lst **stack_b);
void	algo_five(t_lst **stack_a, t_lst **stack_b);
int		is_sorted(t_lst **lst, t_lst *head);
void	algo_four(t_lst **stack_a, t_lst **stack_b);
int		ft_strlen(char *str);

#endif