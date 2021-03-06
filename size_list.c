/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:51:11 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/27 15:51:13 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		size_list(t_file **list)
{
	int		i;
	t_file	*tmp;

	tmp = *list;
	i = 0;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
