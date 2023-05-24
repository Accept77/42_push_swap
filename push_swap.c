/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:02:53 by jinsyang          #+#    #+#             */
/*   Updated: 2023/05/24 16:19:35 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_leak(void)
{
	system("leaks --list -- push_swap");
}

void print(t_stack *stack)
{
	t_list *tmp;
	int count;

	count = 0;
	if (stack->next != NULL)
	{
		tmp = stack->next;
		while (tmp->next != NULL)
		{
			ft_printf("index : %d / data : %d\n",count, tmp->data);
			tmp = tmp->next;
			count++;
		}
		ft_printf("index : %d / data : %d\n\n",count, tmp->data);
	}
	else if (stack->next == NULL)
		ft_printf("Stack is NULL!!!!!!\n");
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	ps_top_reset(&stack_a);
	ps_top_reset(&stack_b);
	if (argc == 1)
		return (0);
	ps_pasing(argv, &stack_a, &stack_b);
	print(&stack_a);
	print(&stack_b);
	sort_stack(&stack_a, &stack_b, argc - 1);
//	atexit(check_leak);
	return (0);
}
