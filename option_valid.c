/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:08:29 by bbrunell          #+#    #+#             */
/*   Updated: 2017/03/17 17:08:32 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	option_valid(char c)
{
	static char	*str = "1alrRtAcdfFgGmnopiSTuU";
	int			i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}
