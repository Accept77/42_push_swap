/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:08:18 by jinsyang          #+#    #+#             */
/*   Updated: 2023/02/26 13:27:49 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_upper(char *p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		if (p[i] >= 97 && p[i] <= 112)
			p[i] -= 32;
		i++;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	if (str == NULL)
		return (count);
	while (str[count])
		count++;
	return (count);
}

int	ft_printchar(char c, int *flag)
{
	*flag = write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *s, int *flag)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		*flag = write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		*flag = write(1, &s[i], 1);
		if (*flag == -1)
			break ;
		i++;
	}
	return (i);
}
