/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:30:17 by jinsyang          #+#    #+#             */
/*   Updated: 2023/02/26 13:27:09 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_printchar(char c, int *flag);
int		ft_printstr(char *s, int *flag);
int		ft_printnbr(int n, int *flag);
size_t	ft_strlen(const char *str);
int		ft_hex(unsigned int i, int up, int *flag, const char *hex);
int		ft_printunsigned(unsigned int n, int *flag);
int		ft_printaddress(void *addr, int *flag);
void	ft_upper(char *p);
#endif
