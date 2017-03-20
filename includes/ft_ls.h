/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 18:34:11 by bbrunell          #+#    #+#             */
/*   Updated: 2017/03/19 18:34:12 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <string.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/acl.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include "../libft/libft.h"
# include <sys/xattr.h>
# include <sys/types.h>
# include <errno.h>

typedef struct		s_option
{
	char			a;
	char			l;
	char			r;
	char			maj_r;
	char			t;
	char			maj_a;
	char			c;
	char			d;
	char			f;
	char			maj_f;
	char			g;
	char			maj_g;
	char			i;
	char			m;
	char			n;
	char			o;
	char			p;
	char			maj_s;
	char			maj_t;
	char			u;
	char			maj_u;
	char			one;
	int				ac;
	char			**av;
}					t_option;

/*
** ac_or_extent : 0 pas d'acl et d'extent
**				  1 extent
**				  2 acl
*/

typedef struct		s_file
{
	struct stat		info;
	struct stat		info_link;
	int				type;
	char			acl_or_extend;
	char			*name;
	char			*path;
	int				major;
	int				minor;
	void			*next;
}					t_file;

typedef struct		s_check_nbr_file
{
	int				directory;
	int				total_file;
}					t_check_nbr_file;
/*
**	nbr_link est la taille de
**	acl_or_extent verifie si il y a un  ou pl
*/

typedef struct		s_l_struct
{
	char			nbr_link;
	char			iud;
	char			gid;
	char			octal;
	char			inode;
	char			major_file;
	char			major;
	char			minor;
	char			acl_or_extend;
	char			octal_or_minor;
}					t_l_struct;

typedef struct		s_directory
{
	char			*path;
	char			*name;
	void			*next;
}					t_directory;

typedef struct		s_file_and_option
{
	t_file			*no_file;
	t_file			*cu_file;
	t_file			*dir_file;
	t_option		opt;
}					t_file_and_option;

typedef struct		s_opt_size
{
	t_option		*opt;
	t_l_struct		*size;
}					t_opt_size;

void				register_file(t_file **l_file, char *path,
DIR **nom_dossier, t_opt_size os);
void				sort_by_alphabet(t_file **l_file, t_file **tmp, char rev);
void				swap(t_file **l_file, t_file **tmp, t_file **temp,
t_file **before);
void				sort_by_mtime(t_file **l_file, t_file **tmp, char rev);
void				register_begin(t_file **l_file, char *path, t_option *opt,
t_l_struct *size);
t_file				*reverse_list(t_file *list);
void				sort(t_file **l_file, t_file **tmp, t_option *opt);
int					begin_by_point(char *str);
int					register_option(char *str, t_option *opt);
int					ft_error(int i, char c);
void				init_option(t_file_and_option *fi_op, t_l_struct *size);
void				list_join(t_file **cu_file, t_file **dir_file);
int					size_list(t_file **list);
void				register_directory(t_directory **sub_dir, char *path,
char *name);
void				print_no_directory(t_file *no_file);
void				print_total_bloc(t_file *tmp, t_buffer *b, t_option *opt);
void				print_file_opt_l(t_file *cu_file, t_l_struct *size,
t_buffer *b, t_option *opt);
void				init_l_struct(t_file **cu_file, t_l_struct *size,
t_option *opt);
void				ls_print_file(t_file **cu_file, int start, t_buffer *b,
t_opt_size os);
void				print_subfolder(char *path, char *name, t_option *opt,
t_buffer *b);
void				no_sort(t_file **l_file, t_file **tmp);
void				print_maj_f(t_file *cu_file, t_option *opt, t_buffer *b);
void				color_file(t_file *cu_file, t_buffer *b);
int					option_valid(char c);
void				sort_by_birthtime(t_file **l_file, t_file **tmp, char rev);
void				sort_by_atime(t_file **l_file, t_file **tmp, char rev);
void				sort_by_size(t_file **l_file, t_file **tmp, t_option *opt);
void				sort_by_ctime(t_file **l_file, t_file **tmp, char rev);
void				register_directory(t_directory **sub_dir, char *path,
char *name);
void				print_time(time_t file_time, t_buffer *b, t_option *opt);
void				color_file(t_file *cu_file, t_buffer *b);
void				put_at_end_of_list(t_file **l_file, t_file **tmp,
t_file **temp, t_file **before);
void				print_type_and_acces(t_file *cu_file, t_buffer *b);
void				print_major_minor(t_file *cu_file, t_l_struct *size,
t_buffer *b, t_option *opt);
void				print_owner(t_file *cu_file, t_l_struct *size, t_buffer *b,
t_option *opt);
void				print_maj_f(t_file *cu_file, t_option *opt, t_buffer *b);
void				init_l_struct(t_file **cu_file, t_l_struct *size,
t_option *opt);
void				print_inode(t_file *cu_file, t_l_struct *size, t_buffer *b);
int					check_extend_and_acl(t_file *cu_file);

#endif
