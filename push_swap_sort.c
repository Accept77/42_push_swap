/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:05:11 by jinsyang          #+#    #+#             */
/*   Updated: 2023/03/26 19:59:43 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition(t_stack *stack_a, t_stack *stack_b, int left, int right)
{
	int		pivot;
	t_list	*tmp;

	tmp = stack_a->next;
	pivot = tmp->data;
	while (left < right)
	{
		if (tmp->data <= pivot)
			ps_rab(stack_a, 'a');
		else if (tmp->data > pivot)
			ps_pab(stack_b, stack_a, 'b');
		tmp = stack_a->next;
		left++;
	}
	ps_rab(stack_a, 'a');
	return (pivot);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b, int left, int right)
{
	partition(stack_a, stack_b, left, right);
}

//	int	pivot;
//
//	if (stacks->next->next == NULL)
//		return ;
//	pivot = partition(stack_a, stack_b, left, right);
//	sort_stack_a(stacks, pivot, right);
//	sort_stack_b(stacks, left, pivot);
