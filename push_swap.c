/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:02:53 by jinsyang          #+#    #+#             */
/*   Updated: 2023/03/08 19:25:37 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_leak(void)
{
	system("leaks --list -- push_swap");
}

void print(t_list *top_a)
{
	t_list *tmp;
	int count;

	tmp = top_a;
	count = 0;
	while (tmp->next != NULL)
	{
		ft_printf("index : %d / data : %d\n",count, tmp->data);
		tmp = tmp->next;
		count++;
	}
	ft_printf("index : %d / data : %d\n\n",count, tmp->data);
}

void print_rev(t_list *top_a)
{
	t_list	*tmp;
	int count;

	tmp = top_a;
	count = 0;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		count++;
	}
	while (tmp->pre != NULL)
	{
		ft_printf("index : %d / data : %d\n",count, tmp->data);
		tmp = tmp->pre;
		count--;
	}
	ft_printf("index : %d / data : %d\n\n",count, tmp->data);
}

void print_all(t_list *top)
{
	print(top);
	print_rev(top);
}

int	main(int argc, char **argv)
{
	t_list	*top_a;
	t_list	*top_b;

	top_a = ps_new_node(111111111);
	top_b = ps_new_node(222222222);
	if (argc == 1)
		return (0);
	ps_pasing(argv, top_a, top_b);
	print(top_a);
	print(top_b);
//	atexit(check_leak);
	return (0);
}
