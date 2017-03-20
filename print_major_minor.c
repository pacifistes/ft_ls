/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_major_minor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 15:35:34 by bbrunell          #+#    #+#             */
/*   Updated: 2017/03/19 15:35:36 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	find_major_space(t_file *cu_file, t_buffer *b, t_option *opt,
t_l_struct *size)
{
	int		size_major;
	int		nbr_space;
	char	size_str;

	size_major = size_long_long(major(cu_file->info.st_rdev)) + 1;
	if (opt->o == 1)
	{
		if (opt->g == 1)
			nbr_space = 3 + (size->major - size_major) + 1;
		else
		{
			size_str = (opt->n == 1) ? size_long_long(cu_file->info.st_uid) :
			ft_strlen((getpwuid(cu_file->info.st_uid))->pw_name);
			nbr_space = 4 + (size->iud - size_str) + (size->major - size_major);
		}
	}
	else
	{
		size_str = (opt->n == 1) ? size_long_long(cu_file->info.st_gid) :
		ft_strlen((getgrgid(cu_file->info.st_gid))->gr_name);
		nbr_space = 3 + (size->gid - size_str) + (size->major - size_major) + 1;
	}
	while (--nbr_space > 0)
		buff_join(" ", b);
}

void		print_major_minor(t_file *cu_file, t_l_struct *size, t_buffer *b,
t_option *opt)
{
	char	size_minor;
	char	nbr_space;
	char	*str;
	char	*str2;

	size_minor = size_long_long(minor(cu_file->info.st_rdev));
	find_major_space(cu_file, b, opt, size);
	str = ft_itoll(cu_file->major);
	buff_join(str, b);
	buff_join(",", b);
	free(str);
	nbr_space = (1 + size->minor - size_minor);
	while (nbr_space > 0)
	{
		buff_join(" ", b);
		nbr_space--;
	}
	str2 = ft_itoll(cu_file->minor);
	buff_join(str2, b);
	free(str2);
}
