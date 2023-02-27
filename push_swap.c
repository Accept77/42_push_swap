/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:02:53 by jinsyang          #+#    #+#             */
/*   Updated: 2023/02/28 02:29:53 by jinsyang         ###   ########.fr       */
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

	tmp = top_a;
	while (tmp->next != NULL)
	{
		ft_printf("%d\n",tmp->data);
		tmp = tmp->next;
	}
	ft_printf("%d\n",tmp->data);
}

int	main(int argc, char **argv)
{
	t_list	*top_a;
	t_list	*top_b;

	top_a = ps_new_node(0);
	top_b = ps_new_node(0);
	if (argc == 1)
		return (0);
	ps_pasing(argv, top_a, top_b);
	print(top_a);
//	atexit(check_leak);
	return (0);
}
