/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiche <bsiche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:02:03 by bsiche            #+#    #+#             */
/*   Updated: 2018/03/02 02:05:17 by bsiche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		ft_normal(t_lstcontainer *liste)
{
	t_ls	*buf;

	liste->firstelement = ft_lstgetfirst(liste->firstelement);
	ft_lexico(liste);
	while (liste->firstelement != NULL)
	{
		buf = liste->firstelement->content;
		ft_putstr(buf->name);
		if (liste->firstelement->next != NULL)
		{
			ft_putstr("\n");
			liste->firstelement = liste->firstelement->next;
		}
		else
			break;
	}
	return (0);
}

char	*ft_total(t_lstcontainer *liste)
{
	char	*total;
	int 	block;
	t_ls	*buf;

	liste->firstelement = ft_lstgetfirst(liste->firstelement);
	block = 0;
	while (liste->firstelement != NULL)
	{
		buf = liste->firstelement->content;
		block += buf->block;
		if (liste->firstelement->next != NULL)
		{
			liste->firstelement = liste->firstelement->next;
		}
		else
			break;
	}
	total = ft_strdup("total ");
	total = ft_strjoin(total, ft_itoa(block), 0);
	total = ft_strjoin(total, "\n", 0);
	liste->firstelement = ft_lstgetfirst(liste->firstelement);
	return (total);
}

int		ft_printlong(t_lstcontainer *liste)
{
	char	m;
	t_ls	*buf;

	liste->firstelement = ft_lstgetfirst(liste->firstelement);
	ft_putstr(ft_total(liste));
	while (liste->firstelement != NULL)
	{
		buf = liste->firstelement->content;
		m = buf->permission[0];
		ft_putstr(buf->permission);
		ft_putstr(buf->itoardlink);
		ft_putchar(' ');
		ft_putstr(buf->usrname);
		ft_putstr(buf->group);
		if (m == 'b' || m == 'c')
			ft_putstr(buf->maj);
		else
			ft_putstr(buf->size);
		ft_putchar(' ');
		ft_putstr(buf->time);
		ft_putchar(' ');
		ft_putstr(buf->name);
		if (liste->firstelement->next != NULL)
		{
			ft_putstr("\n");
			liste->firstelement = liste->firstelement->next;
		}
		else
			break;
	}
	return (0);
}

int		ft_chckmode(char *str, int c)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			flag++;
		}
		i++;
	}
	return (flag);
}

/*int		ft_printls(t_list *rep, char *mod, int z)
{
	int			i;
	int			j;
	int			a;

	i = 0;
	j = 0;
	ft_lexico(rep);
	if ((a = ft_chckmode(mod, 'a')) == 0)
	{
		i = ft_hidden(liste);
	}
	if (i == z)
		return (1);
	ft_apply(dir, mod, i);
	ft_cleanid(dir, i);
	if (ft_chckmode(mod, 'r') > 0)
		ft_rev(dir, z - 1, a);
	if (ft_chckmode(mod, 'l') > 0)
		ft_printlong(dir, i);
	else
		ft_normal(dir, i);
	if ((ft_chckmode(mod, 'R') == 1))
		ft_recur(dir, mod);
	free (dir);
	return (0);
}*/