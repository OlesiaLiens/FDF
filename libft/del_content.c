/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 15:59:00 by oshyiata          #+#    #+#             */
/*   Updated: 2019/03/25 15:59:00 by oshyiata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		del_content(void *content, size_t content_size)
{
	(void)content_size;
	ft_memdel(&content);
}
