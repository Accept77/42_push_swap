/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:52:45 by jinsyang          #+#    #+#             */
/*   Updated: 2023/02/28 02:35:46 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ps_new_node(long long data)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->data = data;
	new->pre = NULL;
	new->next = NULL;
	return (new);
}

void	ps_free_exit(t_list *top_a, t_list *top_b)
{
	t_list	*tmp;
	t_list	*next;

	tmp = top_a;
	while (tmp->next != NULL)
	{
		next = tmp->next;
		free(tmp);
		tmp = NULL;
		tmp = next;
	}
	free(tmp);
	tmp = NULL;
	tmp = top_b;
	while (tmp->next != NULL)
	{
		next = tmp->next;
		free(tmp);
		tmp = NULL;
		tmp = next;
	}
	free(tmp);
	tmp = NULL;
	ft_printf("Error\n");
	exit(0);
}

void	ps_make_lst(long long data, t_list *top_a, t_list *top_b)
{
	t_list	*new;
	t_list	*tmp;
	t_list	*pre;

	tmp = top_a;
	if (!(data <= 2147483647 && data >= -2147483648))
		ps_free_exit(top_a, top_b);
	new = ps_new_node(data);
	while (tmp->next != NULL)
	{
		pre = tmp;
		if (tmp->data == (int)data)
			ps_free_exit(top_a, top_b);
		tmp = tmp->next;
	}
	tmp->next = new;
	new->pre = pre;
}
