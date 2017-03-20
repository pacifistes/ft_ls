/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 15:38:14 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/20 15:38:16 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	reset_opt_1lm(t_option *opt, char c)
{
	opt->l = c;
	opt->one = 0;
	opt->m = 0;
	if (c == 0)
	{
		opt->g = (opt->g == -1 || opt->g == 1) ? -1 : 0;
		opt->n = (opt->n == -1 || opt->n == 1) ? -1 : 0;
		opt->o = (opt->o == -1 || opt->o == 1) ? -1 : 0;
	}
	else
	{
		opt->g = (opt->g == -1 || opt->g == 1) ? 1 : 0;
		opt->n = (opt->n == -1 || opt->n == 1) ? 1 : 0;
		opt->o = (opt->o == -1 || opt->o == 1) ? 1 : 0;
	}
}

static void	reset_opt_ucu(t_option *opt)
{
	opt->c = 0;
	opt->u = 0;
	opt->maj_u = 0;
}

static void	register_this_option(char c, t_option *opt)
{
	opt->a = (c == 'a') ? 1 : opt->a;
	opt->l = (c == 'l') ? 1 : opt->l;
	opt->r = (c == 'r') ? 1 : opt->r;
	opt->maj_r = (c == 'R') ? 1 : opt->maj_r;
	opt->t = (c == 't') ? 1 : opt->t;
	opt->maj_a = (c == 'A') ? 1 : opt->maj_a;
	opt->c = (c == 'c') ? 1 : opt->c;
	opt->d = (c == 'd') ? 1 : opt->d;
	opt->f = (c == 'f') ? 1 : opt->f;
	opt->maj_f = (c == 'F') ? 1 : opt->maj_f;
	opt->g = (c == 'g') ? 1 : opt->g;
	opt->maj_g = (c == 'G') ? 1 : opt->maj_g;
	opt->i = (c == 'i') ? 1 : opt->i;
	opt->m = (c == 'm') ? 1 : opt->m;
	opt->n = (c == 'n') ? 1 : opt->n;
	opt->o = (c == 'o') ? 1 : opt->o;
	opt->p = (c == 'p' && opt->maj_f == 0) ? 1 : opt->p;
	opt->maj_s = (c == 'S') ? 1 : opt->maj_s;
	opt->maj_t = (c == 'T') ? 1 : opt->maj_t;
	opt->u = (c == 'u') ? 1 : opt->u;
	opt->maj_u = (c == 'U') ? 1 : opt->maj_u;
	opt->maj_t = (c == 'T') ? 1 : opt->maj_t;
	opt->one = (c == '1') ? 1 : opt->one;
}

static int	verif_option(char *str)
{
	if (!str || !str[0])
		ft_error(-1, 0);
	if (!ft_strncmp("--", str, 2) && ft_strlen(str) == 2)
		return (2);
	else if (!ft_strncmp("--", str, 2) && ft_strlen(str) > 2)
		ft_error(0, '-');
	else if ((ft_strlen(str) == 1 && str[0] == '-')
	|| (ft_strlen(str) >= 1 && str[0] != '-'))
		return (3);
	return (1);
}

/*
**	les retours d'erreurs :
**	-1 : c une erreur : fts_open : No such file or Directory
**	 2 : le prochain est un dossier
**	 0 : illegal option
**	 3 : c un dossier ou fichier (ou inexistant)
**	 1 : les option sont ok
*/

int			register_option(char *str, t_option *opt)
{
	int i;

	if ((i = verif_option(str)) != 1)
		return (i);
	while (str[i])
	{
		if (!option_valid(str[i]))
			ft_error(0, str[i]);
		if (str[i] == '1' || str[i] == 'm')
			reset_opt_1lm(opt, 0);
		else if (str[i] == 'c' || str[i] == 'U' || str[i] == 'u')
			reset_opt_ucu(opt);
		else if (str[i] == 'F' || str[i] == 'p')
		{
			opt->maj_f = 0;
			opt->p = 0;
		}
		else if (str[i] == 'g' || str[i] == 'l'
		|| str[i] == 'n' || str[i] == 'o')
			reset_opt_1lm(opt, 1);
		register_this_option(str[i], opt);
		i++;
	}
	return (1);
}
