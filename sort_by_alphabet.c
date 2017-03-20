/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_alphabet.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 15:11:30 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/20 15:11:32 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	swap(t_file **l_file, t_file **tmp, t_file **temp, t_file **before)
{
	if (!(*before))
	{
		(*tmp)->next = *temp;
		*l_file = *tmp;
	}
	else
	{
		(*tmp)->next = *temp;
		*temp = *l_file;
		while (ft_strcmp((*before)->name, (*temp)->name))
			*temp = (*temp)->next;
		(*temp)->next = *tmp;
	}
}

void	put_at_end_of_list(t_file **l_file, t_file **tmp, t_file **temp,
t_file **before)
{
	if (!(*temp) && !(*before))
	{
		(*tmp)->next = NULL;
		*l_file = *tmp;
	}
	else if (!(*temp))
	{
		*temp = *l_file;
		while (*temp && (*temp)->next)
			*temp = (*temp)->next;
		(*tmp)->next = NULL;
		(*temp)->next = *tmp;
	}
}

void	sort_by_alphabet(t_file **l_file, t_file **tmp, char rev)
{
	t_file *temp;
	t_file *before;

	temp = *l_file;
	before = NULL;
	while (temp)
	{
		if ((rev == 0 && ft_strcmp((*tmp)->name, temp->name) < 0)
		|| (rev == 1 && ft_strcmp((*tmp)->name, temp->name) > 0))
		{
			swap(l_file, tmp, &temp, &before);
			return ;
		}
		before = temp;
		temp = temp->next;
	}
	put_at_end_of_list(l_file, tmp, &temp, &before);
}
