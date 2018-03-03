/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tableau.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiche <bsiche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 13:41:39 by bsiche            #+#    #+#             */
/*   Updated: 2018/01/28 14:12:28 by bsiche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

char	***ft_taballoc(char *str)
{
	int				i;
	int				j;
	char			***tab;
	DIR				*dir;
	struct dirent	*lu;

	i = 0;
	j = 0;
	if ((dir = opendir(str)) == NULL)
		return (NULL);
	while ((lu = readdir(dir)) != NULL)
	{
		i++;
	}
	printf("nbligne\n%d ", i);
	if ((tab =malloc(sizeof(char **) * i)) == NULL)
		return (NULL);
	while (j <= i)
	{
		if ((tab[j] = malloc(sizeof(char *) * 7)) == NULL)
			return (NULL);
		else
			if ((tab[j][0] = ft_strnew(1)) == NULL)
				return (NULL);
		j++;
	}
	return (tab);
}