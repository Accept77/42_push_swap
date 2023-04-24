/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rule.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 02:37:33 by jinsyang          #+#    #+#             */
/*   Updated: 2023/04/24 17:08:39 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sab(t_stack *stack, char what)
{
	t_list	*tmp;
	t_list	*next;
	t_list	*next_next;

	if (stack->next == NULL || stack->next->next == NULL)
	{
		ft_printf("sab problem!!!!!\n");
		exit(0);
	}
	tmp = stack->next;
	next = tmp->next;
	stack->next = next;
	next->pre = NULL;
	tmp->pre = next;
	tmp->next = next->next;
	next->next = tmp;
	if (tmp->next != NULL)
	{
		next_next = tmp->next;
		next_next->pre = tmp;
	}
	if (what != 'n')
		ft_printf("s%c\n", what);
}

void	ps_ss(t_stack *stack_a, t_stack *stack_b)
{
	ps_sab(stack_a, 'n');
	ps_sab(stack_b, 'n');
	ft_printf("ss\n");
}

void	ps_pab(t_stack *stay, t_stack *move, char what)
{
	t_list	*tmp;
	t_list	*next;

	if (move->next == NULL)
	{
		ft_printf("pab problem!!!!!\n");
		exit(0);
	}
	tmp = move->next;
	if (tmp->next != NULL)
	{
		next = tmp->next;
		next->pre = NULL;
	}
	move->next = tmp->next;
	if (stay->next != NULL)
	{
		next = stay->next;
		next->pre = tmp;
	}
	tmp->next = stay->next;
	stay->next = tmp;
	tmp->pre = NULL;
	ft_printf("p%c\n", what);
}
