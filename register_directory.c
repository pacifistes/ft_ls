/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_directory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 12:57:06 by bbrunell          #+#    #+#             */
/*   Updated: 2017/03/18 12:57:08 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	register_directory(t_directory **sub_dir, char *path, char *name)
{
	t_directory *tmp;
	t_directory *temp;

	temp = *sub_dir;
	tmp = ft_memalloc(sizeof(t_directory));
	tmp->path = ft_strdup(path);
	tmp->name = ft_strdup(name);
	if (!temp)
	{
		tmp->next = *sub_dir;
		*sub_dir = tmp;
	}
	else
	{
		while (temp && temp->next)
			temp = temp->next;
		tmp->next = NULL;
		temp->next = tmp;
	}
}
