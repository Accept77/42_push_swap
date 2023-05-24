/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:05:11 by jinsyang          #+#    #+#             */
/*   Updated: 2023/05/24 19:23:43 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_5(t_stack *stack_a, t_stack *stack_b, int size_a)
{
	int	flag;
	int	pb_count;

	pb_count = 0;
	while (size_a != 3)
	{
		ps_pab(stack_b, stack_a, 'b');
		size_a--;
		pb_count++;
	}
	sort_3(stack_a);
	while (pb_count)
	{
		flag = is_max_min(stack_a, stack_b, size_a); // 이거 문제임
		while (pb_count && flag == 0)
		{
			flag = is_max_min(stack_a, stack_b, size_a);
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
		if (pb_count)
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
	int	size_b;
	int	i;

	size_b = size_a;
	i = 0;
	if (size_a <= 5)
	{
		if (size_a == 2)
			sort_2(stack_a);
		else if (size_a == 3)
			sort_3(stack_a);
		else if (size_a == 4 || size_a == 5)
			sort_a_5(stack_a, stack_b, size_a);
		rotate_up(stack_a);
		return ;
	}
	size_a = part_a(stack_a, stack_b, size_a);
	size_b -= size_a;
	sort_a(stack_a, stack_b, size_a);
	while (i < size_b)
	{
		ps_pab(stack_a, stack_b, 'a');
		i++;
	}
}


// 1. 처음 스택이 5이하인지 점검해서 정렬
// 2. 5이상이라면 part로 5이하될떄까지 나눔
// 3. 나누면서 나머지는 b에 던지고 나중에 다시 회수해서 가져온 수가 5이하라면 정렬
// 어떤 방법으로 가져온 부분만 정렬할꺼임?? 

// 재귀? 아니면 반복문?
