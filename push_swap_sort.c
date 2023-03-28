/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:05:11 by jinsyang          #+#    #+#             */
/*   Updated: 2023/03/28 19:35:27 by jinsyang         ###   ########.fr       */
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
		if (tmp->data < pivot)
			ps_rab(stack_a, 'a');
		else if (tmp->data > pivot)
			ps_pab(stack_b, stack_a, 'b');
		tmp = stack_a->next;
		left++;
	}
	return (pivot);
}

int	a_to_b(t_stack *stack_a, t_stack *stack_b, int size)
{
	t_list	*tmp;
	int		pivot;
	int		i;
	int		ra_count;
	int		pb_count;

	tmp = stack_a->next;
	i = 0;
	ra_count = 0;
	pb_count = 0;
	if (size == 1)
		return (0);
	pivot = tmp->data;
	while (i < size)
	{
		if (tmp->data < pivot)
		{
			ps_rab(stack_a, 'a');
			ra_count++;
		}
		else
		{
			ps_pab(stack_b, stack_a, 'b');
			pb_count++;
		}
		tmp = stack_a->next;
		i++;
	}
	while (ra_count)
	{
		ps_rrab(stack_a, 'a');
		ra_count--;
	}
	return (size - pb_count);
}

int	b_to_a(t_stack *stack_a, t_stack *stack_b, int size)
{
	t_list	*tmp;
	int		pivot;
	int		i;
	int		rb_count;
	int		pa_count;

	tmp = stack_a->next;
	i = 0;
	rb_count = 0;
	pa_count = 0;
	if (size == 1)
	{
		ps_pab(stack_a, stack_b, 'a');
		return (0);
	}
	pivot = tmp->data;
	while (i < size)
	{
		if (tmp->data < pivot)
		{
			ps_rab(stack_b, 'b');
			rb_count++;
		}
		else
		{
			ps_pab(stack_a, stack_b, 'a');
			pa_count++;
		}
		tmp = stack_a->next;
		i++;
	}
	while (rb_count)
	{
		ps_rrab(stack_b, 'b');
		rb_count--;
	}
	return (size - pa_count);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b, int size)
{
	if (size == 0)
		return ;
	size = a_to_b(stack_a, stack_b, size);
	sort_stack(stack_a, stack_b, size);
}

//	int	pivot;
//
//	if (stacks->next->next == NULL)
//		return ;
//	pivot = partition(stack_a, stack_b, left, right);
//	sort_stack_a(stacks, pivot, right);
//	sort_stack_b(stacks, left, pivot);
