/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:05:11 by jinsyang          #+#    #+#             */
/*   Updated: 2023/03/12 19:41:23 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pivot(t_list *top_a, t_list *top_b, int size)
{
	t_list	*tmp;
	t_list	*next;
	int		pivot;
	int		count;

	tmp = top_a->next;
	count = 0;
	while (tmp->next != NULL)
		tmp = tmp->next;
	pivot = tmp->data;
	tmp = top_a->next;
	while (count < size)
	{
		next = tmp->next;
		if (tmp->data > pivot)
			ps_pab(top_b, top_a, 'b');
		else
			ps_rab(top_a, 'a');
		tmp = next;
		count++;
	}
}

void swap(t_list *top_a, t_list *top_b, int argc)
{
	int	size;

	size = argc - 1;
	pivot(top_a, top_b, size);
}
