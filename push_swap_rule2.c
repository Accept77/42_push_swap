/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rule2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:06:49 by jinsyang          #+#    #+#             */
/*   Updated: 2023/03/08 14:31:38 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//- ra : 스택 A의 모든 요소를 위로 한 칸씩 이동시키고 첫 번째 요소를 마지막에 넣습니다.
//- rb : 스택 B의 모든 요소를 위로 한 칸씩 이동시키고 첫 번째 요소를 마지막에 넣습니다.
//- rr : ra와 rb를 모두 수행합니다.
//- rra : 스택 A의 모든 요소를 아래로 한 칸씩 이동시키고 마지막 요소를 첫 번째에 넣습니다.
//- rrb : 스택 B의 모든 요소를 아래로 한 칸씩 이동시키고 마지막 요소를 첫 번째에 넣습니다.
//- rrr : rra와 rrb를 모두 수행합니다.

void	ps_rab(t_list *top, char what)
{
	t_list	*tmp;
	t_list	*next;

	if (top->next == NULL || top->next->next == NULL)
	{
		ft_printf("rab problem!!!!!!\n");
		exit(0);
	}
	tmp = top->next;
	next = tmp->next;
	top->next = next;
	next->pre = top;
	while (next->next != NULL)
		next = next->next;
	tmp->next = NULL;
	tmp->pre = next;
	next->next = tmp;
	ft_printf("r%c\n", what);
}

void	ps_rrab(t_list *top, char what)
{
	t_list	*tmp;
	t_list	*pre;

	if (top->next == NULL || top->next->next == NULL)
	{
		ft_printf("rab problem!!!!!!\n");
		exit(0);
	}
	tmp = top->next;
	while (tmp->next != NULL)
	{
		pre = tmp;
		tmp = tmp->next;
	}
	pre->next = NULL;
	pre = top->next;
	top->next = tmp;
	tmp->pre = top;
	tmp->next = pre;
	pre->pre = tmp;
	ft_printf("rr%c\n", what);
}
