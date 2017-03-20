/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:10:45 by bbrunell          #+#    #+#             */
/*   Updated: 2017/03/03 19:10:47 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_nbr_link(t_file *cu_file, t_l_struct *size, t_buffer *b)
{
	char	size_nbr;
	char	nbr_space;
	char	*str;

	size_nbr = size_long_long(cu_file->info.st_nlink);
	nbr_space = 2 + (size->nbr_link - size_nbr);
	if (cu_file->acl_or_extend >= 1)
		nbr_space--;
	while (nbr_space > 0)
	{
		buff_join(" ", b);
		nbr_space--;
	}
	str = ft_itoll(cu_file->info.st_nlink);
	buff_join(str, b);
	free(str);
}

static void	check_opt_octal_size(t_file *cu_file, int nbr_space, t_buffer *b,
t_opt_size os)
{
	char	size_str;

	if (os.opt->o == 1)
	{
		if (os.opt->g != 1)
		{
			if (os.opt->n == 1)
				size_str = size_long_long(cu_file->info.st_uid);
			else
				size_str = ft_strlen((getpwuid(cu_file->info.st_uid))->pw_name);
			nbr_space = (os.size->iud - size_str) + nbr_space;
		}
	}
	else
	{
		if (os.opt->n == 1)
			size_str = size_long_long(cu_file->info.st_gid);
		else
			size_str = ft_strlen((getgrgid(cu_file->info.st_gid))->gr_name);
		nbr_space = (os.size->gid - size_str) + nbr_space;
	}
	nbr_space++;
	while (--nbr_space > 0)
		buff_join(" ", b);
}

static void	print_octal_size(t_file *cu_file, t_l_struct *size, t_buffer *b,
t_option *opt)
{
	char	size_nbr;
	char	nbr_space;
	char	*str;

	size_nbr = size_long_long(cu_file->info.st_size);
	nbr_space = (size->major_file * size->major + size->major_file * 2 + 2 +
	size->major_file * (size->octal_or_minor - size->octal)) +
	(size->octal - size_nbr);
	check_opt_octal_size(cu_file, nbr_space, b, (t_opt_size){opt, size});
	str = ft_itoll(cu_file->info.st_size);
	buff_join(str, b);
	free(str);
}

static void	print_all_l_information(t_file *cu_file, t_l_struct *size,
t_buffer *b, t_option *opt)
{
	print_type_and_acces(cu_file, b);
	if (cu_file->acl_or_extend >= 1)
		buff_join((cu_file->acl_or_extend >= 9) ? "@" : "+", b);
	print_nbr_link(cu_file, size, b);
	print_owner(cu_file, size, b, opt);
	if (cu_file->type == S_IFCHR || cu_file->type == S_IFBLK)
		print_major_minor(cu_file, size, b, opt);
	else
		print_octal_size(cu_file, size, b, opt);
	if (opt->c == 1)
		print_time(cu_file->info.st_ctime, b, opt);
	else if (opt->u == 1)
		print_time(cu_file->info.st_atime, b, opt);
	else if (opt->maj_u == 1)
		print_time(cu_file->info.st_birthtime, b, opt);
	else
		print_time(cu_file->info.st_mtime, b, opt);
	buff_join(" ", b);
}

void		print_file_opt_l(t_file *cu_file, t_l_struct *size, t_buffer *b,
t_option *opt)
{
	char	str[BUFFER];
	int		taille;

	print_all_l_information(cu_file, size, b, opt);
	if (cu_file->type == S_IFLNK)
	{
		(opt->maj_g == 1) ? color_file(cu_file, b) :
		buff_join(cu_file->name, b);
		if (opt->maj_f == 1)
			print_maj_f(cu_file, opt, b);
		buff_join(" -> ", b);
		taille = readlink(cu_file->path, str, BUFFER);
		str[taille] = 0;
		buff_join(str, b);
	}
	else
	{
		(opt->maj_g == 1) ? color_file(cu_file, b) :
		buff_join(cu_file->name, b);
		if (opt->p == 1 && cu_file->type == S_IFDIR)
			buff_join("/", b);
		if (opt->maj_f == 1)
			print_maj_f(cu_file, opt, b);
	}
	buff_join("\n", b);
}
