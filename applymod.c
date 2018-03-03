/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applymod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiche <bsiche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 01:55:35 by bsiche            #+#    #+#             */
/*   Updated: 2018/02/14 22:34:13 by bsiche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_apply(t_ls *dir, char *mod, int a)
{
	int i;

	i = 0;
	ft_cleantime(dir);
	ft_spacelink(dir, a);
	ft_spacesize(dir, a);
	ft_spaceusr(dir, a);
	ft_spacegroup(dir, a);
	while (mod[i])
	{
		if (mod[i] == 'S')
			ft_sizesort(dir);
		if (mod[i] == 't')
			ft_timesort(dir);
		i++;
	}
}

void	ft_rev(t_ls *dir, int i, int a)
{
	int			j;
	int			k;
	t_ls		tmp;

	j = 0;
	k = 0;
	if (a == 0)
	{
		while (dir[k].name[0] == '.')
		{
			j++;
			k++;
			a = 0;
		}
	}
	while (i > j)
	{
		tmp = dir[j];
		dir[j] = dir[i];
		dir[i] = tmp;
		j++;
		i--;
	}
}