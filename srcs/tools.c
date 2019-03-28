/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:27:45 by oshyiata          #+#    #+#             */
/*   Updated: 2019/02/28 17:27:45 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fdf.h"

void	ft_usage(void)
{
	ft_putendl("usage: ./fdf map_file");
	exit(0);
}

void	invalid_map(void)
{
	ft_putendl("invalid map");
	exit(0);
}
