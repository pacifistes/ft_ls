/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:15:00 by bbrunell          #+#    #+#             */
/*   Updated: 2017/03/17 18:15:03 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		find_year(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	i = i - 2;
	while (i > 0 && str[i] && str[i] != ' ')
		i--;
	return (i);
}

void	print_time(time_t file_time, t_buffer *b, t_option *opt)
{
	time_t	actual_time;
	int		size;
	char	*str;

	time(&actual_time);
	str = ctime(&file_time);
	if (opt->maj_t == 1)
	{
		buff_sub_join(str + 3, b,
		ft_strlen(str) - 4);
	}
	else if (actual_time - file_time < 15768000 && actual_time
	- file_time > -15768000)
		buff_sub_join(str + 3, b, 13);
	else
	{
		size = find_year(str);
		buff_sub_join(str + 3, b, 8);
		buff_sub_join(str + size, b, ft_strlen(str) - (size + 1));
	}
}
