/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_inode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:29:34 by bbrunell          #+#    #+#             */
/*   Updated: 2017/03/17 17:29:38 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_inode(t_file *cu_file, t_l_struct *size, t_buffer *b)
{
	char	size_nbr;
	char	nbr_space;
	char	*str;

	size_nbr = size_long_long(cu_file->info.st_ino);
	nbr_space = size->inode - size_nbr;
	while (nbr_space > 0)
	{
		buff_join(" ", b);
		nbr_space--;
	}
	str = ft_itoll(cu_file->info.st_ino);
	buff_join(str, b);
	buff_join(" ", b);
	free(str);
}
