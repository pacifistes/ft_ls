/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 15:38:00 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/20 15:38:02 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_error(int i, char c)
{
	if (i == -1)
	{
		ft_putendl_fd("ft_ls: fts_open: No such file or directory", 2);
		exit(1);
	}
	else
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putendl_fd(&c, 2);
		ft_putendl_fd("usage: ./ft_ls [-Ralrt] [file ...]", 2);
		exit(1);
	}
	return (0);
}
