/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_no_directory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 18:50:46 by bbrunell          #+#    #+#             */
/*   Updated: 2017/03/03 18:50:50 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_no_directory(t_file *no_file)
{
	struct stat info;

	while (no_file)
	{
		lstat(no_file->name, &info);
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(no_file->name, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
		no_file = no_file->next;
	}
}
