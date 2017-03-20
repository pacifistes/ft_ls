/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 17:16:51 by bbrunell          #+#    #+#             */
/*   Updated: 2017/03/18 17:16:52 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_the_file(t_file **cu_file, t_buffer *b, t_opt_size *os)
{
	if (os->opt->i == 1)
		print_inode(*cu_file, os->size, b);
	if (os->opt->l == 1)
		print_file_opt_l(*cu_file, os->size, b, os->opt);
	else
	{
		if (os->opt->maj_g == 1)
			color_file(*cu_file, b);
		else
			buff_join((*cu_file)->name, b);
		if (os->opt->p == 1 && (*cu_file)->type == S_IFDIR)
			buff_join("/", b);
		if (os->opt->maj_f == 1)
			print_maj_f(*cu_file, os->opt, b);
		else
			buff_join("\n", b);
	}
}

static void	print_name_dir(t_file **cu_file, int start, int c, t_buffer *b)
{
	if (start == 1)
	{
		if (c == 0)
		{
			buff_join_nstr((char*[]){
			(*cu_file)->path, ":\n"}, b, 2);
		}
		else
		{
			buff_join_nstr((char*[]){"\n",
			(*cu_file)->path, ":\n"}, b, 3);
		}
	}
}

void		ls_print_file(t_file **cu_file, int start, t_buffer *b,
t_opt_size os)
{
	t_file	*tmp;
	int		c;

	c = 0;
	while (*cu_file && (((*cu_file)->type) != S_IFDIR || os.opt->d == 1))
	{
		if (os.opt->m == 1 && c != 0)
			buff_join(", ", b);
		print_the_file(cu_file, b, &os);
		*cu_file = (*cu_file)->next;
		c++;
	}
	if (c != 0 && os.opt->m == 1)
		buff_join("\n", b);
	while (*cu_file)
	{
		print_name_dir(cu_file, start, c, b);
		print_subfolder((*cu_file)->path, (*cu_file)->name, os.opt, b);
		c++;
		tmp = *cu_file;
		*cu_file = (*cu_file)->next;
		free(tmp->name);
		free(tmp->path);
		free(tmp);
	}
}
