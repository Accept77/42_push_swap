/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:05:11 by jinsyang          #+#    #+#             */
/*   Updated: 2023/04/10 19:39:46 by jinsyang         ###   ########.fr       */
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

void	sort_a_3(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*tmp;
	int		i;

	tmp = stack_a->next;
	i = 0;
	
}

void	sort_a_5(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*tmp;
	int		flag;
	int		max;
	int		i;

	tmp = stack_a->next;
	flag = 0;
	max = tmp->data;
	i = 0;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (max < tmp->data)
			max = tmp->data;
	}
	while (i < 2)
	{
		ps_pab(stack_b, stack_a, 'b');
		if (stack_b->next->data == max)
			flag = 1;
		i++;
	}
	
}

1 3 2 / 1 2 3 / 2 1 3 / 2 3 1 / 3 1 2 / 3 2 1

1 3 2 / 2 3 1
1 2 3
2 1 3
3 1 2
3 2 1

flag = 1;
 3 1 5 2 4

1 5 2 4 / 3
5 2 4 / 1 3
2 4 5 / 1 3
1 2 4 5 / 3
2 4 5 1 / 3
4 5 1 2 / 3
3 4 5 1 2
2 3 4 5 1
1 2 3 4 5


2개

기준?
제일 적은 걸로 하기

void	sort_stack(t_stack *stack_a, t_stack *stack_b, int size)
{
	if (size <= 3)
		return ;
	size = part(stack_a, stack_b, size);
	sort_stack(stack_a, stack_b, size);
}
