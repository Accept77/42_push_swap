/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:03:40 by jinsyang          #+#    #+#             */
/*   Updated: 2023/02/28 02:31:44 by jinsyang         ###   ########.fr       */
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

int			ft_printf(const char *str, ...);
long long	ps_atoi(char *str);
char		*ps_strdup(const char *s1, int j, int size);
t_list		*ps_new_node(long long data);
void		ps_pasing(char **argv, t_list *top_a, t_list *top_b);
void		ps_free_exit(t_list *top_a, t_list *top_b);
void		ps_make_lst(long long data, t_list *top_a, t_list *top_b);

#endif