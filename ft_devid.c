/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_devid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiche <bsiche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 22:08:12 by bsiche            #+#    #+#             */
/*   Updated: 2018/02/14 01:38:37 by bsiche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t		ft_getidlen(t_ls *dir, int i, int j)
{
	size_t		minsize;
	size_t		majsize;

	minsize = 0;
	majsize = 0;
	while (dir[j].done != 1)
	{
		if (dir[j].permission[0] == 'c' || dir[j].permission[0] == 'b')
		{
			if (ft_strlen(dir[j].maj) > majsize)
				majsize = ft_strlen(dir[j].maj);
			if (ft_strlen(dir[j].min) > minsize)
				minsize = ft_strlen(dir[j].min);
		}
		j++;
	}
	if (i == 0)
		return (majsize);
	else
		return (minsize);
}

void		ft_devmin(t_ls *dir, int i, size_t minlen)
{
	size_t		k;
	size_t		j;
	char		*buf;

	while (dir[i].done != 1)
	{
		if (dir[i].permission[0] == 'c' || dir[i].permission[0] == 'b')
		{
			if (ft_strlen(dir[i].min) < minlen)
			{
				k = 0;
				j = minlen - (ft_strlen(dir[i].min));
				buf = ft_strnew(j);
				while (k < j)
				{
					buf[k] = ' ';
					k++;
				}
				dir[i].min = ft_strjoin(buf, dir[i].min);
			}
		}
		i++;
	}
}

void		ft_devmaj(t_ls *dir, int i, size_t majlen)
{
	size_t		k;
	size_t		j;
	char		*buf;

	while (dir[i].done != 1)
	{
		if (dir[i].permission[0] == 'c' || dir[i].permission[0] == 'b')
		{
			if (ft_strlen(dir[i].maj) < majlen)
			{
				k = 0;
				j = majlen - (ft_strlen(dir[i].maj));
				buf = ft_strnew(j);
				while (k < j)
				{
					buf[k] = ' ';
					k++;
				}
				dir[i].maj = ft_strjoin(buf, dir[i].maj);
			}
		}
		i++;
	}
}

void	ft_cleanid(t_ls *dir, int j)
{
	int		i;
	size_t	majlen;
	size_t	minlen;

	i = 0;
	majlen = ft_getidlen(dir, 0, j);
	minlen = ft_getidlen(dir, 1, j);
	ft_devmin(dir, j, minlen);
	ft_devmaj(dir, j, majlen);
	while (dir[i].done != 1)
	{
		dir[i].maj = ft_strjoin(dir[i].maj, ", ");
		dir[i].maj = ft_strjoin(dir[i].maj, dir[i].min);
		i++;
	}
}