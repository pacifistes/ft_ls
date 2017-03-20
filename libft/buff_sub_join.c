/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_sub_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 18:29:57 by bbrunell          #+#    #+#             */
/*   Updated: 2017/03/19 18:29:59 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	buff_sub_join(char *str, t_buffer *b, int len)
{
	int i;

	i = 0;
	while (str && str[i] && i < len)
	{
		if (b->buff == BUFFER)
		{
			write(1, b->str_buff, b->buff);
			b->buff = 0;
		}
		b->str_buff[b->buff] = str[i];
		b->buff = b->buff + 1;
		i++;
	}
	if (b->buff >= BUFFER)
	{
		write(1, b->str_buff, BUFFER);
		b->buff = 0;
	}
}
