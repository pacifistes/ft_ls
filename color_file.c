/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:26:45 by bbrunell          #+#    #+#             */
/*   Updated: 2017/03/17 18:26:48 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	color_end_check(t_file *cu_file, t_buffer *b)
{
	if ((cu_file->info.st_mode & S_IXUSR)
	|| (cu_file->info.st_mode & S_IXGRP)
	|| (cu_file->info.st_mode & S_IXOTH))
	{
		if (cu_file->info.st_mode & S_ISUID)
			buff_join("\e[38;5;232;48;5;1m", b);
		else if (cu_file->info.st_mode & S_ISGID)
			buff_join("\e[38;5;232;48;5;51m", b);
		else
			buff_join("\e[38;5;1m", b);
	}
}

void		color_file(t_file *cu_file, t_buffer *b)
{
	if (cu_file->type == S_IFDIR)
	{
		if (cu_file->info.st_mode & S_IWOTH)
		{
			buff_join((cu_file->info.st_mode & S_ISVTX) ? "\e[38;5;232;48;5;82m"
			: "\e[38;5;232;48;5;220m", b);
		}
		else
			buff_join("\e[38;5;20m", b);
	}
	else if (cu_file->type == S_IFLNK)
		buff_join("\e[38;5;126m", b);
	else if (cu_file->type == S_IFSOCK)
		buff_join("\e[38;5;82m", b);
	else if (cu_file->type == S_IFIFO)
		buff_join("\e[38;5;220m", b);
	else if (cu_file->type == S_IFBLK)
		buff_join("\e[38;5;20;48;5;51m", b);
	else if (cu_file->type == S_IFCHR)
		buff_join("\e[38;5;20;48;5;220m", b);
	else
		color_end_check(cu_file, b);
	buff_join(cu_file->name, b);
	buff_join("\e[0;0m", b);
}
