/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:58:52 by jinsyang          #+#    #+#             */
/*   Updated: 2023/04/30 18:21:53 by jinsyang         ###   ########.fr       */
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

void	sort_stack(t_stack *stack_a, t_stack *stack_b, int size)
{
	if (size <= 5)
	{
		sort_a(stack_a, stack_b, size);
		print(stack_a);
		print(stack_b);
		return ;
	}
	size = part(stack_a, stack_b, size);
	sort_stack(stack_a, stack_b, size);
}

// 재귀 돌릴떄 고정할 부분 뺴고 돌리는 방법을 생각해보기
// 재귀에서 a 정렬하고 고정 b에서 가져와서 정렬하기
