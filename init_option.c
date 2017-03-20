/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 15:38:07 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/20 15:38:09 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	valid_file(char *str, t_option *opt)
{
	struct stat info;

	if (lstat(str, &info) == -1)
		return (0);
	if (((info.st_mode & S_IFMT) == S_IFDIR) || (opt->l == 0 &&
	(info.st_mode & S_IFMT) == S_IFLNK && stat(str, &info) != -1 &&
	(info.st_mode & S_IFMT) == S_IFDIR))
		return (2);
	return (1);
}

static int	check_option(t_file_and_option *fi_op, int *i, int *is_op,
t_l_struct *size)
{
	int value;

	value = register_option(fi_op->opt.av[*i], &fi_op->opt);
	*is_op = (value >= 2) ? 0 : 1;
	if (value == 2)
	{
		if (*i == fi_op->opt.ac - 1)
		{
			if (fi_op->opt.d == 1)
				register_begin(&fi_op->cu_file, ".", &fi_op->opt, size);
			else
				register_begin(&fi_op->dir_file, "./", &fi_op->opt, size);
			return (1);
		}
		*i = *i + 1;
	}
	return (2);
}

static void	check_file(t_file_and_option *fi_op, t_l_struct *size, int i)
{
	int file_or_dir;

	if (!fi_op->opt.av[i] || !fi_op->opt.av[i][0])
		ft_error(-1, 0);
	file_or_dir = valid_file(fi_op->opt.av[i], &fi_op->opt);
	if (file_or_dir == 1 || (file_or_dir == 2 && fi_op->opt.d == 1))
		register_begin(&fi_op->cu_file, fi_op->opt.av[i], &fi_op->opt, size);
	else if (file_or_dir == 2)
		register_begin(&fi_op->dir_file, fi_op->opt.av[i], &fi_op->opt, size);
	else
		register_begin(&fi_op->no_file, fi_op->opt.av[i], &fi_op->opt, size);
}

void		init_option(t_file_and_option *fi_op, t_l_struct *size)
{
	int	is_op;
	int	i;
	int	value;

	is_op = 1;
	i = 0;
	while (++i < fi_op->opt.ac)
	{
		if (is_op == 1 && (value = check_option(fi_op, &i, &is_op, size)) == 1)
			return ;
		if (is_op == 0)
			check_file(fi_op, size, i);
	}
	if (is_op == 1)
	{
		if (fi_op->opt.d == 1)
			register_begin(&fi_op->cu_file, ".", &fi_op->opt, size);
		else
			register_begin(&fi_op->dir_file, "./", &fi_op->opt, size);
	}
}
