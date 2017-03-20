/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_mtime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 15:17:27 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/20 15:17:29 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_by_mtime(t_file **l_file, t_file **tmp, char rev)
{
	t_file *temp;
	t_file *before;

	temp = *l_file;
	before = NULL;
	while (temp)
	{
		if (rev == 1 && (((*tmp)->info.st_mtime < temp->info.st_mtime)
		|| ((*tmp)->info.st_mtime == temp->info.st_mtime
		&& ft_strcmp((*tmp)->name, temp->name) > 0)))
		{
			swap(l_file, tmp, &temp, &before);
			return ;
		}
		else if (rev == 0 && (((*tmp)->info.st_mtime > temp->info.st_mtime)
		|| ((*tmp)->info.st_mtime == temp->info.st_mtime
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
