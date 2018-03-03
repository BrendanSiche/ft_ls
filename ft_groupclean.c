/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_groupclean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiche <bsiche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 01:33:11 by bsiche            #+#    #+#             */
/*   Updated: 2018/02/14 01:37:53 by bsiche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_getmaxusr(t_ls *dir, int j)
{
	size_t		maxusr;

	maxusr = 0;

	while (dir[j].done != 1)
	{
		if (ft_strlen(dir[j].usrname) > maxusr)
			maxusr = ft_strlen(dir[j].usrname);
		j++;
	}
	return (maxusr);
}

void		ft_spaceusr(t_ls *dir, int a)
{
	int 		i;
	size_t		j;
	size_t		k;
	size_t		max;
	char		*buf;

	max = ft_getmaxusr(dir, a);
	i = 0;
	while (dir[i].done != 1)
	{
		if (ft_strlen(dir[i].usrname) < max)
		{
			k = 0;
			j = max - (ft_strlen(dir[i].usrname));
			buf = ft_strnew(j);
			while (k < j)
			{
				buf[k] = ' ';
				k++;
			}
			dir[i].usrname = ft_strjoin(buf, dir[i].usrname);
		}
		i++;
	}
}