/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_total_bloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 18:52:19 by bbrunell          #+#    #+#             */
/*   Updated: 2017/03/03 18:52:21 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_total_bloc(t_file *tmp, t_buffer *b, t_option *opt)
{
	int		total;
	char	*str;
	int		no_point_file;

	total = 0;
	no_point_file = 0;
	while (tmp)
	{
		if (opt->a == 1)
			total = total + tmp->info.st_blocks;
		if (!begin_by_point(tmp->name))
		{
			no_point_file++;
			total = (opt->a == 0) ? total + tmp->info.st_blocks : total;
		}
		tmp = tmp->next;
	}
	if (opt->a == 0 && no_point_file == 0)
		return ;
	str = ft_itoll(total);
	buff_join_nstr((char*[]){"total ", str, "\n"}, b, 3);
	free(str);
}
