/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:05:11 by jinsyang          #+#    #+#             */
/*   Updated: 2023/04/12 19:46:44 by jinsyang         ###   ########.fr       */
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
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		size_b;

	size_b = 0;
	while (size != 3)
	{
		ps_pab(stack_b, stack_a, 'b');
		size--;
		size_b++;
	}
	sort_a_3(stack_a);
	while (size_b)
	{
		tmp_a = stack_a->next;
		tmp_b = stack_b->next;
		while (tmp_a->next != NULL)
		{
			if (tmp_a->data > tmp_b->data);
			끝자리 가면 생각해보기
			tmp_a = tmp_a->next;
		}
		size_b--;
	}
}

1 2 3 / 5 4 아에 다 작거나
3 4 5 / 1 2 이에 다 크거나
1 4 5 / 3 2 그냥 노말
1 3 5 / 2 4 중간에 넣어야 하거나
어쨋든 스택 뒤에 있는거랑 앞이랑 비교해서 그 다음 큰수가 나오면 옮기기


void	sort_stack(t_stack *stack_a, t_stack *stack_b, int size)
{
	if (size <= 5)
	{
		sort_a_3(stack_a);
		print(stack_a);
		print(stack_b);
		return ;
	}
	size = part(stack_a, stack_b, size);
	sort_stack(stack_a, stack_b, size);
}
