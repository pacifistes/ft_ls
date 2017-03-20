/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_ctime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 13:15:38 by bbrunell          #+#    #+#             */
/*   Updated: 2017/03/18 13:15:39 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_by_ctime(t_file **l_file, t_file **tmp, char rev)
{
	t_file *temp;
	t_file *before;

	temp = *l_file;
	before = NULL;
	while (temp)
	{
		if (rev == 1 && (((*tmp)->info.st_ctime < temp->info.st_ctime)
		|| ((*tmp)->info.st_ctime == temp->info.st_ctime
		&& ft_strcmp((*tmp)->name, temp->name) > 0)))
		{
			swap(l_file, tmp, &temp, &before);
			return ;
		}
		else if (rev == 0 && (((*tmp)->info.st_ctime > temp->info.st_ctime)
		|| ((*tmp)->info.st_ctime == temp->info.st_ctime
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
