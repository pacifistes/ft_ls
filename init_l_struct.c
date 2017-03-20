/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_l_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:49:00 by bbrunell          #+#    #+#             */
/*   Updated: 2017/03/17 17:49:02 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	begin_cmp_size(t_file *tmp, t_l_struct *tmp_size, t_l_struct *size,
t_option *opt)
{
	tmp_size->nbr_link = size_long_long(tmp->info.st_nlink);
	if (opt->n == 0)
	{
		tmp_size->iud = ft_strlen((getpwuid(tmp->info.st_uid))->pw_name);
		tmp_size->gid = ft_strlen((getgrgid(tmp->info.st_gid))->gr_name);
	}
	else
	{
		tmp_size->iud = size_long_long(tmp->info.st_uid);
		tmp_size->gid = size_long_long(tmp->info.st_gid);
	}
	tmp_size->octal = size_long_long(tmp->info.st_size);
	tmp_size->inode = size_long_long(tmp->info.st_ino);
	if (tmp_size->inode > size->inode)
		size->inode = tmp_size->inode;
	if (tmp_size->nbr_link > size->nbr_link)
		size->nbr_link = tmp_size->nbr_link;
	if (tmp_size->iud > size->iud)
		size->iud = tmp_size->iud;
	if (tmp_size->gid > size->gid)
		size->gid = tmp_size->gid;
	if (tmp_size->octal > size->octal)
		size->octal = tmp_size->octal;
}

void		init_l_struct(t_file **cu_file, t_l_struct *size, t_option *opt)
{
	t_file		*tmp;
	t_l_struct	tmp_size;
	char		test;

	test = 0;
	tmp = *cu_file;
	begin_cmp_size(tmp, &tmp_size, size, opt);
	if (check_extend_and_acl(tmp) && test == 0)
		test = 1;
	if (tmp->type == S_IFCHR || tmp->type == S_IFBLK)
	{
		size->major_file = 1;
		tmp_size.minor = minor((*cu_file)->info.st_rdev);
		tmp_size.major = major((*cu_file)->info.st_rdev);
		tmp->major = tmp_size.major;
		tmp->minor = tmp_size.minor;
		tmp_size.major = size_long_long(tmp_size.major);
		tmp_size.minor = size_long_long(tmp_size.minor);
		if (tmp_size.major > size->major)
			size->major = tmp_size.major;
		if (tmp_size.minor > size->minor)
			size->minor = tmp_size.minor;
	}
	if (test == 1)
		size->acl_or_extend = 1;
}
