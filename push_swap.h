/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:03:40 by jinsyang          #+#    #+#             */
/*   Updated: 2023/02/26 19:02:23 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list {
	int	data;
	struct s_list *pre;
	struct s_list *next;
}	t_list;

int	ft_printf(const char *str, ...);
int	push_swap_atoi(char *str);
char	*push_swap_strdup(const char *s1, int j, int size);

#endif
