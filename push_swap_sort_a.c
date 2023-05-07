/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:05:11 by jinsyang          #+#    #+#             */
/*   Updated: 2023/05/07 20:28:09 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_5(t_stack *stack_a, t_stack *stack_b, int pb_count)
{
	int	flag;

	while (pb_count) // b 남기고 a만 정렬해야함
	{
		flag = is_max_min(stack_a, stack_b);
		while (pb_count && flag == 0)
		{
			flag = is_max_min(stack_a, stack_b);
			if (stack_b->next->data > stack_a->next->data &&
				stack_b->next->data < stack_a->next->next->data)
			{
				ps_rab(stack_a, 'a');
				ps_pab(stack_a, stack_b, 'a');
				pb_count--;
			}
			else
				ps_rab(stack_a, 'a');
		}
		rotate_up(stack_a);
		if (stack_b->next != NULL)
		{
			ps_pab(stack_a, stack_b, 'a');
			pb_count--;
			if (stack_a->next->data > stack_a->next->next->data)
				ps_rrab(stack_a, 'a');
		}
	}
}

void	sort_a(t_stack *stack_a, t_stack *stack_b, int size_a)
{
	int	pb_count;

	pb_count = 0;
	if (size_a == 2)
	{
		if (stack_a->next->data > stack_a->next->next->data)
			ps_sab(stack_a, 'a');
		return ;
	}
	while (size_a > 3)
	{
		ps_pab(stack_b, stack_a, 'b');
		pb_count++;
	}
	sort_3(stack_a);
	if (pb_count != 0)
		sort_a_5(stack_a, stack_b, pb_count);
	rotate_up(stack_a);
}
