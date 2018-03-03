/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursiveprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiche <bsiche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 00:24:09 by bsiche            #+#    #+#             */
/*   Updated: 2018/03/03 05:23:11 by bsiche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_keepdir(t_lstcontainer *liste)
{
	t_ls	*buf;
	int		i;
	
	i = 0;
	liste->firstelement = ft_lstgetfirst(liste->firstelement);
	while (liste->firstelement != NULL)
	{
		buf = liste->firstelement->content;
		if (buf->permission[0] == 'd')
		{	
		//	lstcontainer_remove(liste->firstelement);
			i++; 
		}
		if (liste->firstelement->next != NULL)
			liste->firstelement = liste->firstelement->next;
		else
			break ;
	}
	liste->firstelement = ft_lstgetfirst(liste->firstelement);
	return (i);
}

int		ft_rmroot(t_lstcontainer *liste)
{
	t_ls	*buf;

	liste->firstelement = ft_lstgetfirst(liste->firstelement);
	while (liste->firstelement != NULL)
	{
		buf = liste->firstelement->content;
		if (ft_strcmp(buf->name, ".") == 0)
		{	
			if (liste->firstelement->next != NULL)
			{
				liste->firstelement = liste->firstelement->next;
				lstcontainer_remove(liste->firstelement->prev);

			}
			if (ft_strcmp(buf->name, "..") == 0)
			{
				if (liste->firstelement->next != NULL)
				{
					liste->firstelement = liste->firstelement->next;
					lstcontainer_remove(liste->firstelement->prev);
				}
				else 
					return (0);
			}
		}
		if (liste->firstelement->next != NULL)
			liste->firstelement = liste->firstelement->next;
		else
			break;
	}
	return (1);
}

int		ft_testtab(char **tab)
{
	int 	i;

	i = 0;
	while (tab[i])
	{
		ft_putstr("\n\n");
		ft_putstr(tab[i]);
		ft_ls(tab[i], "osef");
		i++;
	}
	free(tab);
	return (0);
}

int		ft_validetab(char * str)
{
	char	*osef;

	osef = ft_strrev(str);

	if (ft_strncmp(osef, "../", 3) == 0 || ft_strncmp(osef, "./", 2) == 0)
	{
		free(osef);
		return (1);
	}
	if (ft_strcmp(osef, "..") == 0 || ft_strcmp(osef, ".") == 0)
		{
		free(osef);
		return (1);
		}
	else
	{
		free(osef);
		return (0);
	}
}

int		ft_validedir(char	*str)
{
	if (str[0] == 'd')
		return (0);
	else
		return (1);
}

int		ft_recursimple(t_lstcontainer *liste)
{
	t_ls	*buf;
	int 	i;


	liste->firstelement = ft_lstgetfirst(liste->firstelement);
//	ft_rmroot(liste);
	i = ft_keepdir(liste);
	liste->firstelement = ft_lstgetfirst(liste->firstelement);
	if (i == 0)
	{
		ft_lstdel(liste->firstelement);
//		free(liste);
		return (0);
	}
	while (liste->firstelement != NULL)
	{
		buf = liste->firstelement->content;
		if (ft_validetab(buf->path) == 0 && ft_validedir(buf->permission) == 0)
		{
			ft_ls(buf->path, "osef");
		}
		if (liste->firstelement->next != NULL)
			liste->firstelement = liste->firstelement->next;
		else
			break;
	}
	if (liste->firstelement != NULL)
		ft_lstdel(liste->firstelement);
//	free(liste);
	return (0);
}