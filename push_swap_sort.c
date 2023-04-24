/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:05:11 by jinsyang          #+#    #+#             */
/*   Updated: 2023/04/24 18:41:23 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	part(t_stack *stack_a, t_stack *stack_b, int size)
{
	int		pivot;
	int		i;
	t_list	*tmp;
	int		ra_count;

	tmp = stack_a->next;
	i = 0;
	pivot = tmp->data;
	ra_count = 0;
	while (i < size)
	{
		if (pivot > tmp->data)
		{
			ps_rab(stack_a, 'a');
			ra_count++;
		}
		else if (pivot <= tmp->data)
			ps_pab(stack_b, stack_a, 'b');
		tmp = stack_a->next;
		i++;
	}
	print(stack_a);
	print(stack_b);
	return (ra_count);
}

int	is_max_min(t_stack *stack_a, t_stack *stack_b)
{
	int		max_min;
	int		flag;
	t_list	*tmp_a;

	flag = 0;
	tmp_a = stack_a->next;
	max_min = 0;
	while (tmp_a != NULL)
	{
		if (stack_b->next->data > tmp_a->data)
			max_min++;
		else if (stack_b->next->data < tmp_a->data)
			max_min--;
		tmp_a = tmp_a->next;
	}
	if (max_min == 3 || max_min == -3)
		flag++;
	return (flag);
}

void	sort_a_2(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->next;
	if (tmp->data > tmp->next->data)
		ps_sab(stack, 'a');
}

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

void	sort_a_5(t_stack *stack_a, t_stack *stack_b, int size)
{
	t_list	*tmp;
	int		flag;

	tmp = stack_a->next;
	while (size != 3)
	{
		ps_pab(stack_b, stack_a, 'b');
		size--;
	}
	sort_a_3(stack_a);
	while (stack_b->next != NULL)
	{
		flag = is_max_min(stack_a, stack_b);
		while (stack_b->next != NULL && flag == 0)
		{
			if (stack_b->next->data > stack_a->next->data &&
				stack_b->next->data < stack_a->next->next->data)
			{
				ps_rab(stack_a, 'a');
				ps_pab(stack_a, stack_b, 'b');
			}
			else
				ps_rab(stack_a, 'a');
		}
		if (stack_b->next != NULL)
		{
			ps_pab(stack_a, stack_b, 'a');
			if (stack_a->next->data < stack_a->next->next->data)
				ps_rrab(stack_a, 'a');
		}
	}
	while (stack_a->next->next->next->next->next->data < stack_a->next->data)
		ps_rrab(stack_a, 'a');
}

// 45123
// 21345
// 51234 !!!
// 23145
// 42135

// 큰거 처리하기
// 어떤 방법으로??
// 큰거를 판단해서 마지막에 돌아가거나 큰거면 바로 넘겨버리고 돌리기
// 판단 방법은?

// 1 2 3 / 5 4 아에 다 작거나
// 3 4 5 / 1 2 이에 다 크거나
// 2 3 4 / 1 5 큰수 작은수 섞여있거나
// 1 4 5 / 3 2 그냥 노말
// 1 3 5 / 2 4 중간에 넣어야 하거나
// 어쨋든 스택 뒤에 있는거랑 앞이랑 비교해서 그 다음 큰수가 나오면 옮기기
// rra 돌리기? 아니면 2개 판단하기

void	sort_stack(t_stack *stack_a, t_stack *stack_b, int size)
{
	if (size <= 5)
	{
		sort_a_5(stack_a, stack_b, size);
		print(stack_a);
		print(stack_b);
		return ;
	}
	size = part(stack_a, stack_b, size);
	sort_stack(stack_a, stack_b, size);
}
