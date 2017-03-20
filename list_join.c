/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:38:23 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/27 15:38:25 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	list_join(t_file **cu_file, t_file **dir_file)
{
	t_file *tmp;

	tmp = *cu_file;
	if (!tmp)
	{
		*cu_file = *dir_file;
		return ;
	}
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = *dir_file;
}
