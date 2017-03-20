/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_subfolder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 16:51:55 by bbrunell          #+#    #+#             */
/*   Updated: 2017/03/19 16:51:56 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_file_of_dir(t_file **cu_file, int c, t_buffer *b,
t_opt_size *os)
{
	if (os->opt->m == 1 && c != 0)
		buff_join(", ", b);
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
		if (os->opt->m != 1)
			buff_join("\n", b);
	}
}

static void	print_and_check_dir(t_file **cu_file, t_buffer *b, t_opt_size os,
t_directory **sub_dir)
{
	t_file	*tmp;
	int		c;

	c = 0;
	while (*cu_file)
	{
		if (!begin_by_point((*cu_file)->name) || os.opt->a == 1
		|| (os.opt->maj_a == 1 && ft_strcmp((*cu_file)->name, ".")
		&& ft_strcmp((*cu_file)->name, "..")))
		{
			print_file_of_dir(cu_file, c, b, &os);
			c++;
		}
		if (os.opt->maj_r == 1 && (*cu_file)->type == S_IFDIR &&
		(!begin_by_point((*cu_file)->name) || (os.opt->a == 1 &&
		ft_strcmp((*cu_file)->name, ".") && ft_strcmp((*cu_file)->name,
		".."))))
			register_directory(sub_dir, (*cu_file)->path, (*cu_file)->name);
		tmp = *cu_file;
		*cu_file = (*cu_file)->next;
		free(tmp->name);
		free(tmp->path);
		free(tmp);
	}
}

static void	print_file(t_file **cu_file, t_option *opt, t_l_struct *size,
t_buffer *b)
{
	t_directory	*sub_dir;
	t_directory	*temp;

	sub_dir = NULL;
	print_and_check_dir(cu_file, b, (t_opt_size){opt, size}, &sub_dir);
	if (opt->m == 1)
		buff_join("\n", b);
	while (sub_dir)
	{
		buff_join_nstr((char*[]){"\n", sub_dir->path, ":\n"}, b, 3);
		print_subfolder(sub_dir->path, sub_dir->name, opt, b);
		temp = sub_dir;
		sub_dir = sub_dir->next;
		free(temp->path);
		free(temp->name);
		free(temp);
	}
}

void		print_subfolder(char *path, char *name, t_option *opt, t_buffer *b)
{
	DIR			*nom_dossier;
	t_file		*cu_file;
	t_l_struct	size;

	nom_dossier = opendir(path);
	if (nom_dossier == NULL)
	{
		buff_join_nstr((char*[]){"ft_ls: ", name, ": ",
		strerror(errno), "\n"}, b, 5);
		return ;
	}
	cu_file = NULL;
	if (opt->l == 1)
		ft_bzero(&size, sizeof(t_l_struct));
	register_file(&cu_file, path, &nom_dossier, (t_opt_size){opt, &size});
	size.major = size.major + 1;
	size.octal_or_minor = size.minor;
	if (opt->l == 1)
		print_total_bloc(cu_file, b, opt);
	closedir(nom_dossier);
	print_file(&cu_file, opt, &size, b);
}
