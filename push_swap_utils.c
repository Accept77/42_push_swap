/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:30:45 by jinsyang          #+#    #+#             */
/*   Updated: 2023/02/26 19:26:20 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*push_swap_strdup(const char *s1, int j, int size)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *) malloc(sizeof(char) * size + 1);
	if (!(result))
		return (NULL);
	while (i < size)
	{
		result[i] = s1[j];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	push_swap_atoi(char *str)
{
	int	sign;
	int	i;
	int	result;

	sign = 1;
	i = 0;
	result = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return (result * sign);
}
