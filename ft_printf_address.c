/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:54:51 by jinsyang          #+#    #+#             */
/*   Updated: 2023/01/16 18:42:36 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_turn_hex(unsigned long long i, int *flag)
{
	const char	*hex;
	char		p[17];
	int			count;

	hex = "0123456789abcdef";
	count = 0;
	if (i == 0)
	{
		*flag = write(1, "0", 1);
		return (1);
	}
	while (i != 0)
	{
		p[count] = hex[i % 16];
		i /= 16;
		count++;
	}
	p[count] = '\0';
	while (--count >= 0)
	{
		*flag = write(1, &p[count], 1);
		if (*flag == -1)
			break ;
	}
	return (ft_strlen(p));
}

int	ft_printaddress(void *addr, int *flag)
{
	unsigned long long	i;
	int					count;

	count = 0;
	i = (unsigned long long)addr;
	*flag = write(1, "0x", 2);
	if (*flag == -1)
		return (count);
	count = ft_turn_hex(i, flag);
	count += 2;
	return (count);
}
