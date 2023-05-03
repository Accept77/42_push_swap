/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:05:11 by jinsyang          #+#    #+#             */
/*   Updated: 2023/05/03 14:36:03 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_3(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->next;
	if (tmp->data > tmp->next->data)
		ps_sab(stack, 'a');
	tmp = stack->next;
	if (tmp->next->data > tmp->next->next->data)
		ps_rrab(stack, 'a');
	tmp = stack->next;
	if (tmp->data > tmp->next->data)
		ps_sab(stack, 'a');
}

int	is_max_min(t_stack *stack_a, t_stack *stack_b)
{
	int		max_min;
	int		flag;
	int		stack_len;
	t_list	*tmp_a;

	flag = 0;
	tmp_a = stack_a->next;
	max_min = 0;
	stack_len = 0;
	while (tmp_a != NULL)
	{
		if (stack_b->next->data > tmp_a->data)
			max_min++;
		else if (stack_b->next->data < tmp_a->data)
			max_min--;
		tmp_a = tmp_a->next;
		stack_len++;
	}
	if (max_min == stack_len || max_min == -(stack_len))
		flag++;
	return (flag);
}

void	rotate_a(t_stack *stack_a)
{
	t_list	*tmp;

	tmp = stack_a->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp->data < stack_a->next->data)
	{
		ps_rrab(stack_a, 'a');
		tmp = stack_a->next;
		while (tmp->next != NULL)
			tmp = tmp->next;
	}
}

void	sort_a_5(t_stack *stack_a, t_stack *stack_b)
{
	int	flag;

	while (stack_b->next != NULL)
	{
		flag = is_max_min(stack_a, stack_b);
		while (stack_b->next != NULL && flag == 0)
		{
			flag = is_max_min(stack_a, stack_b);
			if (stack_b->next->data > stack_a->next->data &&
				stack_b->next->data < stack_a->next->next->data)
			{
				ps_rab(stack_a, 'a');
				ps_pab(stack_a, stack_b, 'a');
			}
			else
				ps_rab(stack_a, 'a');
		}
		rotate_a(stack_a);
		if (stack_b->next != NULL)
		{
			ps_pab(stack_a, stack_b, 'a');
			if (stack_a->next->data > stack_a->next->next->data)
				ps_rrab(stack_a, 'a');
		}
	}
}

void	sort_a(t_stack *stack_a, t_stack *stack_b, int size)
{
	if (size == 2)
	{
		if (stack_a->next->data > stack_a->next->next->data)
			ps_sab(stack_a, 'a');
		return ;
	}
	while (size > 3)
	{
		ps_pab(stack_b, stack_a, 'b');
		size--;
	}
	sort_a_3(stack_a);
	if (stack_b->next != NULL)
		sort_a_5(stack_a, stack_b);
	rotate_a(stack_a);
}
