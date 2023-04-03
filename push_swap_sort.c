/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:05:11 by jinsyang          #+#    #+#             */
/*   Updated: 2023/04/03 19:15:20 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_stack *stack_a, t_stack *stack_b, int size)
{
	t_list	*tmp;
	int		pivot;
	int		i;
	int		ra_count;
	int		pb_count;

	if (size <= 1)
		return ;
	tmp = stack_a->next;
	pivot = tmp->data;
	ra_count = 0;
	pb_count = 0;
	i = 0;
	while (i < size)
	{
		if (tmp->data < pivot)
		{
			ps_rab(stack_a, 'a');
			ra_count++;
		}
		else if (tmp->data >= pivot)
		{
			ps_pab(stack_b, stack_a, 'b');
			if (stack_b->next->data == pivot)
				ps_rab(stack_b, 'b');
			pb_count++;
		}
		tmp = stack_a->next;
		i++;
	}
	i = 0;
	while (i < ra_count)
	{
		ps_rrab(stack_a, 'a');
		i++;
	}
	print(stack_a);
	print(stack_b);
	a_to_b(stack_a, stack_b, ra_count);
//	b_to_a(stack_a, stack_b, pb_count);
}

void	b_to_a(t_stack *stack_a, t_stack *stack_b, int size)
{
	t_list	*tmp;
	int		pivot;
	int		i;

	if (size <= 1)
	{
		if (size == 1)
			ps_pab(stack_a, stack_b, 'a');
		return ;
	}
	tmp = stack_b->next;
	pivot = tmp->data;
	i = 0;
	while (i < size)
	{
		
	}
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b, int size)
{
	a_to_b(stack_a, stack_b, size);
}
