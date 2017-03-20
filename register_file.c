/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 13:44:46 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/17 13:44:47 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	complete_tmp(t_file *tmp, struct dirent *file, struct stat info,
char *path_file)
{
	tmp->name = ft_strdup(file->d_name);
	tmp->info = info;
	tmp->type = info.st_mode & S_IFMT;
	tmp->path = ft_strdup(path_file);
}

static void	lst_add_file(t_file **l_file, struct dirent *file, char *path,
t_opt_size os)
{
	t_file		*tmp;
	struct stat	info;
	char		*path_file;

	if (!ft_strcmp(path, "./") || !ft_strcmp(path, "/"))
	{
		path_file = ft_free_njoin((char**)(char*[]){path,
		(*file).d_name}, 2, (int *)(int[]){0, 0});
	}
	else
	{
		path_file = ft_free_njoin((char**)(char*[]){path, "/",
		(*file).d_name}, 3, (int*)(int[]){0, 0, 0});
	}
	tmp = ft_memalloc(sizeof(t_file));
	if (!tmp)
		return ;
	lstat(path_file, &info);
	complete_tmp(tmp, file, info, path_file);
	if (os.opt->l == 1 && (!begin_by_point(tmp->name) || os.opt->a == 1))
		init_l_struct(&tmp, os.size, os.opt);
	if (os.opt->i == 1 && size_long_long(tmp->info.st_ino) > os.size->inode)
		os.size->inode = size_long_long(tmp->info.st_ino);
	free(path_file);
	sort(l_file, &tmp, os.opt);
}

void		register_file(t_file **l_file, char *path, DIR **nom_dossier,
t_opt_size os)
{
	struct dirent *file;

	while ((file = readdir(*nom_dossier)))
		lst_add_file(l_file, file, path, os);
}

static void	register_begin_path(t_file *tmp, t_option *opt, char *path,
struct stat info)
{
	if (tmp->type == S_IFDIR)
		tmp->path = ft_strdup(path);
	else if ((info.st_mode & S_IFMT) == S_IFLNK && stat(path, &info) != -1 &&
	(info.st_mode & S_IFMT) == S_IFDIR)
	{
		tmp->path = ft_strdup(path);
		if (opt->l == 0)
			tmp->type = info.st_mode & S_IFMT;
	}
	else
		tmp->path = ft_free_njoin((char*[]){"./", path}, 2, (int[]){0, 0});
}

void		register_begin(t_file **l_file, char *path, t_option *opt,
t_l_struct *size)
{
	t_file		*tmp;
	struct stat	info;

	tmp = ft_memalloc(sizeof(t_file));
	if (!tmp)
		return ;
	tmp->name = ft_strdup(path);
	if ((lstat(path, &info) != -1))
	{
		tmp->info = info;
		tmp->type = info.st_mode & S_IFMT;
		register_begin_path(tmp, opt, path, info);
		if (opt->l == 1 && (tmp->type != S_IFDIR || opt->d == 1))
			init_l_struct(&tmp, size, opt);
		if (opt->i == 1 && size_long_long(tmp->info.st_ino) > size->inode)
			size->inode = size_long_long(tmp->info.st_ino);
		sort(l_file, &tmp, opt);
		return ;
	}
	tmp->path = ft_strdup(path);
	(opt->f == 1) ? no_sort(l_file, &tmp) : sort_by_alphabet(l_file, &tmp, 0);
}
