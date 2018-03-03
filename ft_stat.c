/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiche <bsiche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 18:37:54 by bsiche            #+#    #+#             */
/*   Updated: 2018/03/03 06:10:05 by bsiche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*ft_stat(char *buf, struct dirent *lu)
{
	struct stat		*tmp;
	t_ls			*info;
	time_t			cur;

	cur = time(NULL);
	tmp = malloc(sizeof(struct stat));
	if ((info = malloc(sizeof(t_ls))) == NULL)
	{
				return (NULL);
	}
	if ((lstat(buf, tmp)) == -1)
	{
		ft_putstr(strerror(errno));
		return (NULL);
	}
	info->permission = ft_strdup(ft_usrmode(tmp->st_mode));
	info->name = ft_strdup(lu->d_name);
	info->time = ft_strdup(ctime(&tmp->st_mtime));
	info->epoch = (tmp->st_mtime);
	info->size = (ft_itoa(tmp->st_size));
	if (((cur - tmp->st_mtime) > 15778476) || ((tmp->st_mtime - cur) > 15778476))
		info->timeswitch = 1;
	info = ft_stat2(info, tmp);
	if (info->permission[0] == 'l' || info->permission[0] == 'c' ||
										info->permission[0] == 'b')
		info = ft_stat3(info, tmp, buf);
	free(tmp);
	return (info);
}

t_ls	*ft_stat2(t_ls *info, struct stat *tmp)
{
	info->done = 0;
	info->hardlink = tmp->st_nlink;
	info->block = tmp->st_blocks;
	info->itoardlink = ft_strdup((ft_itoa(tmp->st_nlink)));
	info->usrname = ft_strjoin((ft_getusr(tmp->st_uid)), "  ", 0);
	info->group = ft_strjoin((ft_getgroup(tmp->st_gid)), "  ", 0);
	info->time = ft_strtrim(info->time);
	return (info);
}

t_ls	*ft_stat3(t_ls *info, struct stat *tmp, char *str)
{
	char		*symlink;
	char		*fleche;

	if (info->permission[0] == 'l')
	{
		symlink = ft_strnew(tmp->st_size);
		readlink(str, symlink, tmp->st_size + 1);
		fleche = ft_strnew(4);
		fleche = " -> ";
		symlink = ft_strjoin(fleche, symlink, 0);
		info->name = ft_strjoin(info->name, symlink, 0);
	}
	if (info->permission[0] == 'c' || info->permission[0] == 'b')
	{
		info->maj = ft_strdup(ft_itoa(major(tmp->st_rdev)));
		info->min = ft_strdup(ft_itoa(minor(tmp->st_rdev)));
	}
	else
	{
		info->min = ft_strdup("nope");
		info->maj = ft_strdup("nope");
	}
	return (info);
}