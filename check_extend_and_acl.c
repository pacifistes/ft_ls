/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extend_and_acl.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:42:14 by bbrunell          #+#    #+#             */
/*   Updated: 2017/03/17 17:42:15 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		check_extend_and_acl(t_file *cu_file)
{
	acl_t	acl;

	cu_file->acl_or_extend = 0;
	acl = acl_get_file(cu_file->path, ACL_TYPE_EXTENDED);
	if (listxattr(cu_file->path, 0, 0, XATTR_NOFOLLOW) > 0)
		cu_file->acl_or_extend = 10;
	if (acl)
		cu_file->acl_or_extend = cu_file->acl_or_extend + 1;
	acl_free((void *)acl);
	return (cu_file->acl_or_extend);
}
