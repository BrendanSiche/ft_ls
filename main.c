/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiche <bsiche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:29:49 by bsiche            #+#    #+#             */
/*   Updated: 2018/02/28 00:39:58 by bsiche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "ft_ls.h"
#include <sys/stat.h>
#include <stdlib.h>
#include "libft.h"

int		ft_stopmod(char **argv, char **str, int i, int *flag)
{
	if (argv[i + 1] == NULL)
	{
		*flag = 1;
		ft_ls(".", *str);
		return (i);
	}
	i++;
	return (i);
}

int		ft_mainmod(char **argv, char **str, int *flag)
{
	char	*buf;
	int 	i;

	i = 1;
	while (argv[i][0] == '-')
	{	
		if ((ft_strcmp(argv[i], "--")) == 0)
		{
			return ((ft_stopmod(argv, str, i, flag)));
		}
		buf = ft_strdup(ft_themmods(argv[i]));
		*str = ft_strjoin(*str, buf, 0);
		if (argv[i + 1] != NULL)
			i++;
		else
		{
			ft_ls(".", *str);
			*flag = 1;
			return (i);
		}
	}
	return (i);
}

int		main(int argc, char **argv)
{
	int				i;
	char			*str;
	int				flag;

	i = 1;
	flag = 0;
	str = ft_strnew(0);
	if (argc == 1)
	{
		ft_ls(".", "0");
		return (0);
	}
	i = ft_mainmod(argv, &str, &flag);
	while (argc > i && flag != 1)
	{
		ft_putstr(argv[i]);
		ft_putstr(":\n");
		ft_ls(argv[i], str);
		if (argv[i + 1] != NULL)
			ft_putstr("\n\n");
		i++;
	}
	return (0);
}