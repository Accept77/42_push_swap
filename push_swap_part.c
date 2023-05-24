/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:58:52 by jinsyang          #+#    #+#             */
/*   Updated: 2023/05/24 18:09:55 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	part_a(t_stack *stack_a, t_stack *stack_b, int size)
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
	return (ra_count);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	size_a;
	int	size_b;

	size_a = part_a(stack_a, stack_b, size);
	print(stack_a);
	ft_printf("==========\nsize_a = %d\n==========\n",size_a);
	size_b = size - size_a;
	sort_a(stack_a, stack_b, size_a);
	// sort_b(stack_a, stack_b, size_b);
	print(stack_a);
	print(stack_b);
	// return_a(stack_a, stack_b);
}

// 5이하가 될때까지 재귀 돌려서 pivot기준으로 반으로 나누고
// 그 이하는 정렬하고 나머지는 다시 가져와서 정렬하면 되는거아님?
