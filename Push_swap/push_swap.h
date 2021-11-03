/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <naben-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:18:50 by naben-za          #+#    #+#             */
/*   Updated: 2021/09/24 08:52:20 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

struct	s_node
{
	int				data;
	int				index;
	struct s_node	*p_next;
	struct s_node	*p_prev;
};

typedef struct s_dlist
{
	size_t			lenght;
	struct s_node	*p_head;
	struct s_node	*p_tail;
}				t_Dlist;

// dlist.c
t_Dlist	*dlist_new(void);
void	dlist_append2(t_Dlist **p_list, int data, struct s_node **p_new);
int		dlist_append(t_Dlist *p_list, int data);
void	dlist_delete(t_Dlist **p_list);

// instructions.c
void	dlist_swap1(t_Dlist **p_list, struct s_node *tmp3);
void	dlist_swap(t_Dlist **p_list);
void	dlist_rotate(t_Dlist **p_list);
void	dlist_rrotate(t_Dlist **p_list);

// instruction2.c
void	dlist_push1(t_Dlist **p_list, struct s_node *p_tmpa);
void	dlist_push2(t_Dlist **p_list, struct s_node *p_tmpb2);
void	dlist_push(t_Dlist **p_list1, t_Dlist **p_list2);

// three_random_case
void	case_1(t_Dlist **p_list);
void	case_2(t_Dlist **p_list);
void	case_3(t_Dlist **p_list);
void	case_4(t_Dlist **p_list);
void	case_5(t_Dlist **p_list);

// sort.c
void	find_lowest(t_Dlist **p_list);
void	two_random(t_Dlist **p_list);
void	three_random(t_Dlist **p_list);
void	four_five_random(t_Dlist **p_a, t_Dlist **p_b);
void	sort_with_instructions(size_t *l_pos, size_t *mid, t_Dlist **p_list);

// utils_errors.c
long	ft_atoi2(const char *nptr, t_Dlist **p_a, t_Dlist **p_b);
long	check_value(char *str, t_Dlist **p_a, t_Dlist **p_b);
int		check_double(t_Dlist **p_list);
int		list_sorted(t_Dlist **p_list);
void	ft_free(t_Dlist **p_a, t_Dlist **p_b);

// utils_radix
int		*create_copy(t_Dlist **p_list);
void	sort_copy(int *tab, t_Dlist **p_a);
void	set_index(t_Dlist **p_a, int *tab);

// print.c
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_puterr(t_Dlist **p_a, t_Dlist **p_b);

// main.c
void	dlist_pa_all(t_Dlist **p_a, t_Dlist **p_b);
void	radix(t_Dlist **p_a, t_Dlist **p_b, int max_bits, size_t len);
void	launch_radix(t_Dlist **p_a, t_Dlist **p_b);
void	launch_algo(t_Dlist **p_a, t_Dlist **p_b);

#endif
