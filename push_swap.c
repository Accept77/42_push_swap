/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:02:53 by jinsyang          #+#    #+#             */
/*   Updated: 2023/02/26 19:27:56 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_list *top_a;
	t_list *top_b;
	int i;
	int j;
	int data;
	int size;
	char *tmp;

	top_a = (t_list *)malloc(sizeof(t_list));
	top_b = (t_list *)malloc(sizeof(t_list));
	top_a->data = 0;
	top_b->data = 0;
	top_a->pre = NULL;
	top_b->pre = NULL;
	top_a->next = NULL;
	top_b->next = NULL;
	i = 1;
	if (argc == 1)
		return (0);
	while (argv[i])
	{
		j = 0;
		size = 1;
		while (argv[i][j])
		{
			if (argv[i][j + 1] == ' ' || argv[i][j + 1] == '\0')
			{
				tmp = push_swap_strdup(argv[i], j, size);
				size = -1;
				data = push_swap_atoi(tmp);
				ft_printf("%d\n", data);
				free(tmp);
			}
			size++;
			j++;
		}
		i++;
	}
	return (0);
}
