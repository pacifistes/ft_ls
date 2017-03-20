/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 13:43:12 by bbrunell          #+#    #+#             */
/*   Updated: 2017/03/18 13:43:17 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort(t_file **l_file, t_file **tmp, t_option *opt)
{
	if (opt->f == 1)
		no_sort(l_file, tmp);
	else if (opt->maj_s == 1)
		sort_by_size(l_file, tmp, opt);
	else if (opt->maj_u == 1 && opt->t == 1)
		sort_by_birthtime(l_file, tmp, opt->r);
	else if (opt->u == 1 && opt->t == 1)
		sort_by_atime(l_file, tmp, opt->r);
	else if (opt->c == 1 && opt->t == 1)
		sort_by_ctime(l_file, tmp, opt->r);
	else if (opt->t == 1)
		sort_by_mtime(l_file, tmp, opt->r);
	else
		sort_by_alphabet(l_file, tmp, opt->r);
}
