/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 15:11:08 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/20 15:11:10 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*reverse_list(t_file *list)
{
	t_file *tmp;
	t_file *new;

	tmp = NULL;
	new = NULL;
	while (list)
	{
		tmp = list;
		list = tmp->next;
		tmp->next = new;
		new = tmp;
	}
	return (new);
}
