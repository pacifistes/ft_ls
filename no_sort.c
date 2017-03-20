/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:47:48 by bbrunell          #+#    #+#             */
/*   Updated: 2017/03/17 17:47:53 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	no_sort(t_file **l_file, t_file **tmp)
{
	t_file *temp;

	temp = *l_file;
	if (!temp)
		*l_file = *tmp;
	else
	{
		while (temp && temp->next)
			temp = temp->next;
		(*tmp)->next = NULL;
		temp->next = *tmp;
	}
}
