/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:30:51 by jinsyang          #+#    #+#             */
/*   Updated: 2023/05/24 18:09:33 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *stack)
{
	if (stack->next->data > stack->next->next->data)
		ps_sab(stack, 'a');
}

void	sort_3(t_stack *stack)
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

int	is_max_min(t_stack *stack_a, t_stack *stack_b, int size_a) // 해당 b에 있는 값이 맥스나 민인지 확인
{
	int		max_min;
	int		flag;
	int		stack_len;
	t_list	*tmp_a;

	flag = 0;
	tmp_a = stack_a->next;
	max_min = 0;
	stack_len = 0;
	while (stack_len < size_a)
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

void	rotate_up(t_stack *stack) // a 오름차순으로 돌리는 함수
{
	t_list	*tmp;

	tmp = stack->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp->data < stack->next->data)
	{
		ps_rrab(stack, 'a');
		tmp = stack->next;
		while (tmp->next != NULL)
			tmp = tmp->next;
	}
}

void	rotate_down(t_stack *stack) // b 내림차순으로 돌리는 함수
{
	t_list	*tmp;

	tmp = stack->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp->data > stack->next->data)
	{
		ps_rab(stack, 'b');
		tmp = stack->next;
		while (tmp->next != NULL)
			tmp = tmp->next;
	}
}
