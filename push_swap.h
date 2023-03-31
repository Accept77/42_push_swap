/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:03:40 by jinsyang          #+#    #+#             */
/*   Updated: 2023/03/31 17:04:50 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list {
	int				data;
	struct s_list	*pre;
	struct s_list	*next;
}	t_list;

typedef struct s_stack {
	t_list	*next;
}	t_stack;

void print(t_stack *stack);

int			ft_printf(const char *str, ...);
long long	ps_atoi(char *str);
char		*ps_strdup(const char *s1, int j, int size);
t_list		*ps_new_node(long long data);
void		ps_pasing(char **argv, t_stack *stack_a, t_stack *stack_b);
void		ps_free_exit(t_stack *stack_a, t_stack *stack_b);
void		ps_make_lst(long long data, t_stack *stack_a, t_stack *stack_b);

void		ps_sab(t_stack *stack, char what);
void		ps_pab(t_stack *stay, t_stack *move, char what);
void		ps_rab(t_stack *stack, char what);
void		ps_rrab(t_stack *stack, char what);

void		ps_top_reset(t_stack *stack);
void		sort_stack(t_stack *stack_a, t_stack *stack_b, int size);

#endif
 