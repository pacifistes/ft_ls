/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_owner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 17:14:51 by bbrunell          #+#    #+#             */
/*   Updated: 2017/03/19 17:14:53 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_group(t_file *cu_file, t_buffer *b, t_option *opt)
{
	char	*str2;

	if (opt->o == 1)
		return ;
	if (opt->n == 0)
		str2 = ft_strdup((getgrgid(cu_file->info.st_gid))->gr_name);
	else
		str2 = ft_itoll(cu_file->info.st_gid);
	buff_join(str2, b);
	free(str2);
}

void		print_owner(t_file *cu_file, t_l_struct *size, t_buffer *b,
t_option *opt)
{
	char	size_str;
	char	nbr_space;
	char	*str;

	buff_join(" ", b);
	if (opt->g == 0)
	{
		if (opt->n == 1)
		{
			size_str = size_long_long(cu_file->info.st_uid);
			str = ft_itoll(cu_file->info.st_uid);
		}
		else
		{
			size_str = ft_strlen((getpwuid(cu_file->info.st_uid))->pw_name);
			str = ft_strdup((getpwuid(cu_file->info.st_uid))->pw_name);
		}
		buff_join(str, b);
		free(str);
		nbr_space = 2 + (size->iud - size_str) + 1;
		while (opt->o != 1 && --nbr_space > 0)
			buff_join(" ", b);
	}
	print_group(cu_file, b, opt);
}
