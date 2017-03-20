/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_birthtime.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 13:16:05 by bbrunell          #+#    #+#             */
/*   Updated: 2017/03/18 13:16:06 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_by_birthtime(t_file **l_file, t_file **tmp, char rev)
{
	t_file *temp;
	t_file *before;

	temp = *l_file;
	before = NULL;
	while (temp)
	{
		if (rev == 1 && (((*tmp)->info.st_birthtime < temp->info.st_birthtime)
		|| ((*tmp)->info.st_birthtime == temp->info.st_birthtime
		&& ft_strcmp((*tmp)->name, temp->name) > 0)))
		{
			swap(l_file, tmp, &temp, &before);
			return ;
		}
		else if (rev == 0 && (((*tmp)->info.st_birthtime >
		temp->info.st_birthtime) || ((*tmp)->info.st_birthtime ==
		temp->info.st_birthtime && ft_strcmp((*tmp)->name, temp->name) < 0)))
		{
			swap(l_file, tmp, &temp, &before);
			return ;
		}
		before = temp;
		temp = temp->next;
	}
	put_at_end_of_list(l_file, tmp, &temp, &before);
}
