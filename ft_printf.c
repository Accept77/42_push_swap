/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:33:54 by jinsyang          #+#    #+#             */
/*   Updated: 2023/01/16 18:41:49 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_what(va_list lst, int i, const char *str, int *flag)
{
	int			count;
	const char	*hex;

	hex = "0123456789abcdef";
	count = 0;
	if (str[i] == 'c')
		count = ft_printchar(va_arg(lst, int), flag);
	else if (str[i] == 's')
		count = ft_printstr(va_arg(lst, char *), flag);
	else if (str[i] == 'p')
		count = ft_printaddress(va_arg(lst, void *), flag);
	else if (str[i] == 'd' || str[i] == 'i')
		count = ft_printnbr(va_arg(lst, int), flag);
	else if (str[i] == 'u')
		count = ft_printunsigned(va_arg(lst, unsigned int), flag);
	else if (str[i] == 'x')
		count = ft_hex(va_arg(lst, unsigned int), 0, flag, hex);
	else if (str[i] == 'X')
		count = ft_hex(va_arg(lst, unsigned int), 1, flag, hex);
	else if (str[i] == '%')
	{
		*flag = write(1, "%", 1);
		count = 1;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list			lst;
	unsigned int	count;
	int				i;
	int				flag;

	count = 0;
	i = -1;
	flag = 0;
	va_start(lst, str);
	while (str[++i])
	{
		if (str[i] == '%')
			count += ft_print_what(lst, ++i, str, &flag);
		else
		{
			flag = write(1, &str[i], 1);
			count++;
		}
		if (flag == -1)
			return (-1);
	}
	va_end(lst);
	if (count > 2147483647)
		return (-1);
	return (count);
}
