/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_and_acces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 15:30:24 by bbrunell          #+#    #+#             */
/*   Updated: 2017/03/19 15:30:26 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_acces(t_file *cu_file, t_buffer *b)
{
	buff_join((cu_file->info.st_mode & S_IRUSR) ? "r" : "-", b);
	buff_join((cu_file->info.st_mode & S_IWUSR) ? "w" : "-", b);
	if (cu_file->info.st_mode & S_ISUID)
		buff_join((cu_file->info.st_mode & S_IXUSR) ? "s" : "S", b);
	else
		buff_join((cu_file->info.st_mode & S_IXUSR) ? "x" : "-", b);
	buff_join((cu_file->info.st_mode & S_IRGRP) ? "r" : "-", b);
	buff_join((cu_file->info.st_mode & S_IWGRP) ? "w" : "-", b);
	if (cu_file->info.st_mode & S_ISGID)
		buff_join((cu_file->info.st_mode & S_IXGRP) ? "s" : "S", b);
	else
		buff_join((cu_file->info.st_mode & S_IXGRP) ? "x" : "-", b);
	buff_join((cu_file->info.st_mode & S_IROTH) ? "r" : "-", b);
	buff_join((cu_file->info.st_mode & S_IWOTH) ? "w" : "-", b);
	if (cu_file->info.st_mode & S_ISVTX)
	{
		buff_join((cu_file->info.st_mode & S_IXOTH) ? "t" : "T", b);
		cu_file->acl_or_extend = cu_file->acl_or_extend - 1;
	}
	else
		buff_join((cu_file->info.st_mode & S_IXOTH) ? "x" : "-", b);
}

void		print_type_and_acces(t_file *cu_file, t_buffer *b)
{
	if (cu_file->type == S_IFREG)
		buff_join("-", b);
	else if (cu_file->type == S_IFDIR)
		buff_join("d", b);
	else if (cu_file->type == S_IFLNK)
		buff_join("l", b);
	else if (cu_file->type == S_IFIFO)
		buff_join("p", b);
	else if (cu_file->type == S_IFSOCK)
		buff_join("s", b);
	else if (cu_file->type == S_IFCHR)
		buff_join("c", b);
	else if (cu_file->type == S_IFBLK)
		buff_join("b", b);
	print_acces(cu_file, b);
}
