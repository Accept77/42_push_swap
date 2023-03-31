/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:05:11 by jinsyang          #+#    #+#             */
/*   Updated: 2023/03/31 17:39:20 by jinsyang         ###   ########.fr       */
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

void	a_to_b(t_stack *stack_a, t_stack *stack_b, int size)
{
	t_list	*tmp;
	int		pivot;
	int		i;
	int		ra_count;
	int		pb_count;

	if (size == 1 || size == 0)
		return ;
	tmp = stack_a->next;
	i = 0;
	ra_count = 0;
	pb_count = 0;
	pivot = tmp->data;
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
			if (pivot == stack_b->next->data)
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
}

void	b_to_a(t_stack *stack_a, t_stack *stack_b, int size)
{
	t_list	*tmp;
	int		pivot;
	int		i;
	int		rb_count;
	int		pa_count;

	if (size == 1 || size == 0)
	{
		if (size == 1)
			ps_pab(stack_a, stack_b, 'a');
		return ;
	}
	tmp = stack_b->next;
	i = 0;
	rb_count = 0;
	pa_count = 0;
	pivot = tmp->data;
	while (i < size)
	{
		if (tmp->data < pivot)
		{
			ps_rab(stack_b, 'b');
			rb_count++;
		}
		else if (tmp->data >= pivot)
		{
			ps_pab(stack_a, stack_b, 'a');
			if (pivot == stack_a->next->data)
				ps_rab(stack_a, 'a');
			pa_count++;
		}
		tmp = stack_b->next;
		i++;
	}
	i = 0;
	while (i < rb_count)
	{
		ps_rrab(stack_b, 'b');
		i++;
	}
	print(stack_a);
	print(stack_b);
	b_to_a(stack_a, stack_b, rb_count);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b, int size)
{
	a_to_b(stack_a, stack_b, size);
	b_to_a(stack_a, stack_b, size);
	a_to_b(stack_a, stack_b, size);
	b_to_a(stack_a, stack_b, size);
}
