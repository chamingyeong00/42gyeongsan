/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:12:55 by micha             #+#    #+#             */
/*   Updated: 2025/02/16 09:12:56 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				val;
	int				index;
	struct s_stack	*next;
}	t_stack;

int		worlds_count(char **s, char c);
void	stack_free(t_stack *st);
void	tmp_free(char **tmp);
int		ft_error(void);
int		is_valid(char *argv_point);
int		is_duplicate(long *arr, int cnt, long num);
int		is_sorted(t_stack **head, int cnt);
int		handle_numbers(char **argv_res, long *seen_numbers, int *seen_cnt);
t_stack	*make_new_node(int num);
int		is_check_error(int argc, char **argv, int cnt);
void	insert_stack(t_stack **a_stack, int num);
t_stack	*init_stack(int argc, char **argv);
void	set_index(t_stack *bottom, int cnt);
int		find_big_index(t_stack *bottom);
int		find_bit(int bigg_nbr);
void	small_radix_sort(t_stack **head);
void	middle_radix_sort(t_stack **a_stack, t_stack **b_stack, int cnt);
void	big_radix_sort(t_stack **a_stack, t_stack **b_stack);
void	push(t_stack **stack_from, t_stack **stack_to);
void	push_a(t_stack **a_stack, t_stack **b_stack);
void	push_b(t_stack **a_stack, t_stack **b_stack);
void	swap(t_stack **head);
void	swap_a(t_stack **head);
void	swap_b(t_stack **head);
void	swap_ab(t_stack **a_stack, t_stack **b_stack);
void	rotate(t_stack **head);
void	rotate_a(t_stack **head);
void	rotate_b(t_stack **head);
void	rotate_ab(t_stack **a_stack, t_stack **b_stack);
void	reverse_rotate(t_stack **head);
void	reverse_rotate_a(t_stack **head);
void	reverse_rotate_b(t_stack **head);
void	reverse_rotate_ab(t_stack **a_stack, t_stack **b_stack);

#endif 
