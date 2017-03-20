/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_maj_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:26:54 by bbrunell          #+#    #+#             */
/*   Updated: 2017/03/17 17:26:56 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	whiteout	: '%'
**	directory	: '/'
**	socket		: '='
**	symb_link	: '@'
**	fifo		: '|'
**	executalble : '*'
*/

void	print_maj_f(t_file *cu_file, t_option *opt, t_buffer *b)
{
	if (cu_file->type == S_IFWHT)
		buff_join("%", b);
	else if (cu_file->type == S_IFDIR)
		(opt->p == 0) ? buff_join("/", b) : (void)opt;
	else if (cu_file->type == S_IFSOCK)
		buff_join("=", b);
	else if (cu_file->type == S_IFLNK)
		buff_join("@", b);
	else if (cu_file->type == S_IFIFO)
		buff_join("|", b);
	else if ((cu_file->info.st_mode & S_IXUSR)
	|| (cu_file->info.st_mode & S_IXGRP)
	|| (cu_file->info.st_mode & S_IXOTH))
		buff_join("*", b);
}
