/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 17:31:04 by oshyiata          #+#    #+#             */
/*   Updated: 2019/03/22 17:11:34 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int						ft_my_atoi(const char *str, int *i)
{
	int					sign;
	unsigned long int	res;

	sign = 1;
	res = 0;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	if (str[*i] == '+' && sign == 1)
		(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		res = ((res * 10) + str[*i] - '0');
		if (res > 9223372036854775807U && sign == 1)
			return (-1);
		else if (res > 9223372036854775808U && sign == -1)
			return (0);
		(*i)++;
	}
	return (res * sign);
}
