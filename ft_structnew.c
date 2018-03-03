/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiche <bsiche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 05:14:00 by bsiche            #+#    #+#             */
/*   Updated: 2018/02/01 05:29:31 by bsiche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	ft_structalloc(t_ls dest)
{
	dest.name = ft_strnew(0);
	dest.permission = ft_strnew(0);
	dest.date = ft_strnew(0);
	dest.symlink = ft_strnew(0);
	dest.size= ft_strnew(0);
	dest.path = ft_strnew(0);
	dest.usrname= ft_strnew(0);
	dest.group = ft_strnew(0);
	dest.itoardlink= ft_strnew(0);
	dest.spacing = ft_strnew(0);
	dest.block = 0;
	dest.hardlink = 0;
	dest.epoch = 0;
	dest.timeswitch = 0;
	return (dest);
}

t_ls	ft_struccpy(t_ls orig)
{
	t_ls	dest;

	dest.name = ft_strdup(orig.name);
	dest.permission = ft_strdup(orig.permission);
	dest.date = ft_strdup(orig.date);
	dest.symlink = ft_strdup(orig.symlink);
	dest.size= ft_strdup(orig.size);
	dest.path = ft_strdup(orig.path);
	dest.usrname= ft_strdup(orig.usrname);
	dest.group = ft_strdup(orig.group);
	dest.itoardlink= ft_strdup(orig.itoardlink);
	dest.spacing = ft_strdup(orig.spacing);
	dest.block = orig.block;
	dest.hardlink = orig.hardlink;
	dest.epoch = orig.epoch;
	dest.timeswitch = orig.timeswitch;
	return (dest);
}