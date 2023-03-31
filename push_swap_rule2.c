/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rule2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:06:49 by jinsyang          #+#    #+#             */
/*   Updated: 2023/03/31 17:15:46 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rab(t_stack *stack, char what)
{
	t_list	*tmp;
	t_list	*next;

	if (stack->next != NULL && stack->next->next == NULL)
		return ;
	if (stack->next == NULL && stack->next->next == NULL)
	{
		ft_printf("rab problem!!!!!!\n");
		exit(0);
	}
	tmp = stack->next;
	next = tmp->next;
	stack->next = next;
	next->pre = NULL;
	while (next->next != NULL)
		next = next->next;
	tmp->next = NULL;
	tmp->pre = next;
	next->next = tmp;
	ft_printf("r%c\n", what);
}

void	ps_rrab(t_stack *stack, char what)
{
	t_list	*tmp;
	t_list	*pre;

	if (stack->next != NULL && stack->next->next == NULL)
		return ;
	if (stack->next == NULL && stack->next->next == NULL)
	{
		ft_printf("rrab problem!!!!!!\n");
		exit(0);
	}
	tmp = stack->next;
	while (tmp->next != NULL)
	{
		pre = tmp;
		tmp = tmp->next;
	}
	pre->next = NULL;
	pre = stack->next;
	stack->next = tmp;
	tmp->pre = NULL;
	tmp->next = pre;
	pre->pre = tmp;
	ft_printf("rr%c\n", what);
}
