/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:30:45 by jinsyang          #+#    #+#             */
/*   Updated: 2023/02/28 02:29:52 by jinsyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_pasing(char **argv, t_list *top_a, t_list *top_b)
{
	int			i;
	int			j;
	int			size;
	char		*tmp;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		size = 1;
		while (argv[i][j])
		{
			if (argv[i][j + 1] == ' ' || argv[i][j + 1] == '\0')
			{
				tmp = ps_strdup(argv[i], j, size);
				size = -1;
				ps_make_lst(ps_atoi(tmp), top_a, top_b);
				free(tmp);
			}
			size++;
			j++;
		}
	}
}

char	*ps_strdup(const char *s1, int j, int size)
{
	char	*result;
	int		i;

	i = 0;
	j -= size - 1;
	result = (char *) malloc(sizeof(char) * size + 1);
	if (!(result))
		return (NULL);
	while (i < size)
	{
		result[i] = s1[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}

long long	ps_atoi(char *str)
{
	int			sign;
	int			i;
	long long	result;

	sign = 1;
	i = 0;
	result = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = (result * 10) + str[i] - '0';
		else
		{
			result = 2147483649;
			break ;
		}
		i++;
	}
	return (result * sign);
}
