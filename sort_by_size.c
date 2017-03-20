/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 13:15:30 by bbrunell          #+#    #+#             */
/*   Updated: 2017/03/18 13:15:32 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_by_size(t_file **l_file, t_file **tmp, t_option *opt)
{
	t_file *temp;
	t_file *before;

	temp = *l_file;
	before = NULL;
	while (temp)
	{
		if (opt->r == 1 && (((*tmp)->info.st_size < temp->info.st_size)
		|| ((*tmp)->info.st_size == temp->info.st_size
		&& ft_strcmp((*tmp)->name, temp->name) > 0)))
		{
			swap(l_file, tmp, &temp, &before);
			return ;
		}
		else if (opt->r == 0 && (((*tmp)->info.st_size > temp->info.st_size)
		|| ((*tmp)->info.st_size == temp->info.st_size
		&& ft_strcmp((*tmp)->name, temp->name) < 0)))
		{
			swap(l_file, tmp, &temp, &before);
			return ;
		}
		before = temp;
		temp = temp->next;
	}
	put_at_end_of_list(l_file, tmp, &temp, &before);
}
