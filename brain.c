/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiche <bsiche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 14:43:57 by bsiche            #+#    #+#             */
/*   Updated: 2018/03/03 06:34:15 by bsiche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <errno.h>


int		ft_countf(char *str)
{
	DIR				*dir;
	struct dirent	*lu;
	int 			i;

	i = 0;
	if ((dir = opendir(str)) == NULL)
	{
		ft_putstr(strerror(errno));
		return (0);
	}
	while ((lu = readdir(dir)) != NULL)
	{
		i++;
	}
	if ((closedir(dir)) != 0)
		ft_putstr(strerror(errno));
	return (i);
}

char	*ft_path(char *loc, char *name)
{
	char	*tmp;

	tmp = ft_strjoin(loc, "/", 0);
	tmp = ft_strjoin(tmp, name, 0);
	return (tmp);
}


t_lstcontainer	*ft_org(DIR *dir, char *loc)
{
	struct dirent	*lu;
	char			*buf;
	t_ls			*tmp;
	t_lstcontainer	*liste;
	int 			i;

	i = 0;
	if(ft_strcmp(loc, "/") != 0)
		loc = ft_strjoin(loc, "/", 0);
	liste = lstcontainer_new();
	buf = ft_strnew(0);
	while ((lu = readdir(dir)) != NULL)
	{
		buf = ft_strjoin(loc, lu->d_name, 0);
		tmp = ft_stat(buf, lu);
		if (tmp != NULL)
		{
		tmp->path = ft_strdup(buf);
		liste->add(liste, tmp, sizeof(t_ls *));
		ft_lstgetlast(liste->firstelement)->content = tmp;
		}
		else
			return (NULL);
	}
	free(buf);
	closedir(dir);
	return (liste);
}

void	ft_printest(t_lstcontainer *liste)
{
	t_ls	*buf;
	char	m;

	liste->firstelement = ft_lstgetfirst(liste->firstelement);
	while (liste->firstelement != NULL)
	{
		buf = liste->firstelement->content;
		ft_putstr(buf->permission);
		m = buf->permission[0];
		ft_putstr(buf->permission);
		ft_putchar('\n');
		if (liste->firstelement->next != NULL)
			liste->firstelement = liste->firstelement->next;
		else
			break;
	}
}

t_lstcontainer	*ft_chkerror(char *loc)
{
	DIR		*dir;

	dir = NULL;
	if (ft_strncmp(loc, "/dev/fd", 6) == 0)
	{
		ft_putstr("ft_ls: 4: directory causes a cycle");
		return (NULL);
	}
	if ((dir = opendir(loc)) == NULL)
	{
		ft_putstr(strerror(errno));
		return (NULL);
	}
	return (ft_org(dir, loc));
}

int		ft_ls2(char *loc)
{
	t_lstcontainer	*liste;
	
	if (ft_strcmp(loc, "/dev/fd") == 0)
		return (1);
	if ((liste = ft_chkerror(loc)) == NULL)
		return (0);
	liste = ft_chkerror(loc);
//	ft_errordir(liste);
	ft_lexico(liste);
	ft_printlong(liste);
	ft_keepdir(liste);
	ft_recursimple(liste);
//	ft_printls(liste, mod, i)
	return (0);
}

int		ft_ls(char *loc, char *mod)
{
	int				i;
	t_lstcontainer	*liste;

	(void)mod;
	i = ft_countf(loc);
	if (i == 0)
		return (0);
	if ((liste = ft_chkerror(loc)) == NULL)
		return (0);
	ft_putstr("\n\n");
//	ft_lstdel(liste->firstelement);
	ft_putendl(loc);
//	ft_lexico(liste);
	if (i != 2)
//	ft_timesort(liste);
//	ft_normal(liste);
	ft_printlong(liste);
//	ft_putstr("Fin print classique \n\n");
	ft_recursimple(liste);
//	free(liste);
//	ft_printls(liste, mod, i)
	return (0);
}
