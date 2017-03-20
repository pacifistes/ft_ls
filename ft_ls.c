/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 15:37:52 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/20 15:37:56 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_file_and_option	fi_op;
	t_check_nbr_file	nbr;
	t_buffer			b;
	t_l_struct			size;

	b.buff = 0;
	ft_bzero(&fi_op, sizeof(t_file_and_option));
	ft_bzero(&size, sizeof(t_l_struct));
	fi_op.opt.ac = ac;
	fi_op.opt.av = av;
	init_option(&fi_op, &size);
	if (fi_op.opt.f == 1)
		fi_op.opt.a = 1;
	nbr.directory = size_list(&fi_op.dir_file);
	list_join(&fi_op.cu_file, &fi_op.dir_file);
	nbr.total_file = size_list(&fi_op.cu_file) + size_list(&fi_op.no_file);
	print_no_directory(fi_op.no_file);
	ls_print_file(&fi_op.cu_file,
	(nbr.directory >= 1 && nbr.total_file > 1) ? 1 : 0, &b,
	(t_opt_size){&fi_op.opt, &size});
	write(1, b.str_buff, b.buff);
	return (0);
}
