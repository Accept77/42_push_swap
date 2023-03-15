/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:05:11 by jinsyang          #+#    #+#             */
/*   Updated: 2023/03/15 20:03:03 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pivot(t_stack *stack_a, t_stack *stack_b, int count)
{
	t_list	*tmp;
	t_list	*next;
	int		pivot;
	int		i;
	int		re;

	tmp = stack_a->next;
	i = 0;
	re = 0;
	while (re < count - 1 && tmp->next != NULL)
	{
		tmp = tmp->next;
		re++;
	}
	pivot = tmp->data;
	tmp = stack_a->next;
	while (i < count)
	{
		next = tmp->next;
		if (tmp->data > pivot)
		{
			ps_pab(stack_b, stack_a, 'b');
			re--;
		}
		else
			ps_rab(stack_a, 'a');
		tmp = next;
		i++;
	}
	return (re);
}

void	swap(t_stack *stack_a, t_stack *stack_b, int argc)
{
	int	count;

	count = argc - 1;
	count = pivot(stack_a, stack_b, count);
	count = pivot(stack_a, stack_b, count);
}

// size-1 까지 돌리면 멘뒤 뺴고 가능 분류는?
// 1 5 7 8 3 6 2 4
// 아니면 옮기면서 같이 정렬? 처음 들어간 값을 피벗으로 정하고 큰값 왼 작은값 오?
// 피벗 지정 방법
