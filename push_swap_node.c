/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:52:45 by jinsyang          #+#    #+#             */
/*   Updated: 2023/03/15 18:33:10 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_top_reset(t_stack *stack)
{
	stack->next = NULL;
}

t_list	*ps_new_node(long long data)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = data;
	new->pre = NULL;
	new->next = NULL;
	return (new);
}

void	ps_free_stack(t_stack *stack)
{
	t_list	*tmp;
	t_list	*next;

	if (stack->next != NULL)
	{
		tmp = stack->next;
		while (tmp->next != NULL)
		{
			next = tmp->next;
			free(tmp);
			tmp = NULL;
			tmp = next;
		}
		free(tmp);
	}
}

void	ps_free_exit(t_stack *stack_a, t_stack *stack_b)
{
	ps_free_stack(stack_a);
	ps_free_stack(stack_b);
	ft_printf("Error\n");
	exit(0);
}

void	ps_make_lst(long long data, t_stack *stack_a, t_stack *stack_b)
{
	t_list	*new;
	t_list	*tmp;

	if (!(data <= 2147483647 && data >= -2147483648))
		ps_free_exit(stack_a, stack_b);
	new = ps_new_node(data);
	if (!new)
		ps_free_exit(stack_a, stack_b);
	if (stack_a->next != NULL)
	{
		tmp = stack_a->next;
		while (tmp->next != NULL)
		{
			if (tmp->data == (int)data)
				ps_free_exit(stack_a, stack_b);
			tmp = tmp->next;
		}
		tmp->next = new;
		new->pre = tmp;
	}
	else if (stack_a->next == NULL)
		stack_a->next = new;
}
