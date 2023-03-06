/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rule.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 02:37:33 by jinsyang          #+#    #+#             */
/*   Updated: 2023/03/06 19:28:11 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//- sa : 스택 A의 가장 위에 있는 두 개의 요소를 서로 바꿉니다.
//- sb : 스택 B의 가장 위에 있는 두 개의 요소를 서로 바꿉니다.
//- ss : sa와 sb를 모두 수행합니다.
//- pa : 스택 B의 가장 위에 있는 요소를 스택 A의 가장 위에 넣습니다.
//- pb : 스택 A의 가장 위에 있는 요소를 스택 B의 가장 위에 넣습니다.
//- ra : 스택 A의 모든 요소를 위로 한 칸씩 이동시키고 첫 번째 요소를 마지막에 넣습니다.
//- rb : 스택 B의 모든 요소를 위로 한 칸씩 이동시키고 첫 번째 요소를 마지막에 넣습니다.
//- rr : ra와 rb를 모두 수행합니다.
//- rra : 스택 A의 모든 요소를 아래로 한 칸씩 이동시키고 마지막 요소를 첫 번째에 넣습니다.
//- rrb : 스택 B의 모든 요소를 아래로 한 칸씩 이동시키고 마지막 요소를 첫 번째에 넣습니다.
//- rrr : rra와 rrb를 모두 수행합니다.
//

void	ps_sab(t_list *top, char what)
{
	t_list	*tmp;
	t_list	*next;
	t_list	*next_next;

	if (top->next == NULL || top->next->next == NULL)
	{
		ft_printf("sab problem!!!!!\n");
		exit(0);
	}
	tmp = top->next;
	next = tmp->next;
	top->next = next;
	next->pre = top;
	tmp->pre = next;
	tmp->next = next->next;
	next->next = tmp;
	if (tmp->next != NULL)
	{
		next_next = next->next;
		next_next->pre = tmp;
	}
	if (what != 'n')
		ft_printf("s%c\n", what);
}

void	ps_ss(t_list *top_a, t_list *top_b)
{
	ps_sab(top_a, 'n');
	ps_sab(top_b, 'n');
	ft_printf("ss\n");
}

void	ps_pab(t_list *top, t_list *move, char what)
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
		next->pre = move;
	}
	move->next = tmp->next;
	if (top->next != NULL)
	{
		next = top->next;
		next->pre = tmp;
	}
	tmp->next = top->next;
	top->next = tmp;
	tmp->pre = top;
	ft_printf("p%c\n", what);
}

void	ps_rab(t_list *top, char what)
{
	t_list	*tmp;

	tmp = top->next;


}

//void	ps_rrab(t_list *top, char what)
//{
//}
