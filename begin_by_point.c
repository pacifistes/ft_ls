/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_by_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 15:21:20 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/20 15:21:21 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			begin_by_point(char *str)
{
	if (str && str[0] == '.')
		return (1);
	return (0);
}
