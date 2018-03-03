/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiche <bsiche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 14:11:11 by bsiche            #+#    #+#             */
/*   Updated: 2018/02/26 03:04:32 by bsiche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ismod(char *str)
{
	if (str[0] == '-')
		return (1);
	else
		return (0);
}

char	*ft_themmods(char *str)
{
	int 	i;
	int		j;
	char	*bits;

	bits = ft_strnew(ft_strlen(str));
	if (str[0] != '-')
		return (NULL);
	i = 1;
	j = 0;
	while (str[i])
	{
		if (str[i] == 'a' || str[i] == 'R' || str[i] == 'l' || str[i] == 't'
		|| str[i] == 'S' || str[i] == 'r')
		{
			bits[j] = str[i];
			j++;
		}
		i++;
	}
	return (bits);
}