/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:58:52 by jinsyang          #+#    #+#             */
/*   Updated: 2023/05/07 20:29:23 by jinsyang         ###   ########.fr       */
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

void	sort_stack(t_stack *stack_a, t_stack *stack_b, int size_a)
{
	if (size_a <= 5)
	{
		sort_a(stack_a, stack_b, size_a);
		print(stack_a);
		print(stack_b);
		return ;
	}
	size_a = part(stack_a, stack_b, size_a);
	print(stack_a);
	print(stack_b);
	sort_stack(stack_a, stack_b, size_a);
}

// 재귀 돌릴떄 고정할 부분 뺴고 돌리는 방법을 생각해보기
// 재귀에서 a 정렬하고 고정 b에서 가져와서 정렬하기
// part 함수 완성해보기
// 재귀를 이해해보기?
// 재귀를 써야함?

// 5 / 5 로 나뉘면 정렬하는거고
// 3 / 7 로 나뉘면
// 3 정렬하고 7을 2개로 나눠서 다시 옮기고 정렬하기
// sort함수의 조건을 다 바꿔야 함
// 다 시 해 야 해

// b를 정렬해야함
// a 오름차순 b 내림차순 정렬한다음 합치기?
// 피벗 기준으로 a를 나누고 정렬 시작
// 일단 a를 5이하로 만들고 나머지는 b로 넘김
// 5이하 정렬하고 b에서 가져옴 계속 정렬 (재귀)
// a가 정렬 완료 되면 b도 똑같이 피벗 기준으로 나누고 정렬 하고 합치기(내림차순으로)
// 마지막으로 합치기?
