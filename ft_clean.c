/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiche <bsiche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 00:36:57 by bsiche            #+#    #+#             */
/*   Updated: 2018/02/17 03:05:56 by bsiche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*ft_cleantime(t_list *rep)
{
	int 		i;
	char		*tmp;
	char		*tmp2;
	t_list		*buf;

	i = 0;
	buf = ft_lstgetfirst(rep);
	while (buf != NULL)
	{
		tmp = ft_strdup(buf.content->time[4]);
		buf.content-> = ft_strdup(tmp);
		if (buf.content->timeswitch == 1)
		{
			tmp2 = ft_strnew(7);
			ft_strncpy(tmp2, buf.content->time, 7);
			tmp2 = ft_strjoin(tmp2, &tmp[15]);
			buf.content->time = ft_strdup(tmp2);
		}
		else
		{
			tmp2 = ft_strnew(12);
			buf.content->time = ft_strdup(ft_strncpy(tmp2, buf.content->time, 12));
		}
		buf = buf->next;
	}
	return (buf);
}

int		ft_getmaxlen(t_list *rep, int i, int j)
{
	size_t		maxsize;
	size_t		maxlink;
	size_t		maxgroup;
	t_list		*tmp;

	maxsize = 0;
	maxlink = 0;
	maxgroup = 0;
	tmp = ft_lstgefirst(rep);
	while (tmp != NULL)
	{
		if (ft_strlen(tmp.content->itoardlink) > maxlink)
			maxlink = ft_strlen(tmp.content->itoardlink);
		if (ft_strlen(tmp.content->size) > maxsize)
			maxsize = ft_strlen(tmp.content->size);
		if (ft_strlen(tmp.content->group) > maxgroup)
			maxgroup = ft_strlen(tmp.content->group);
		tmp = tmp->next;
	}
	if (i == 0)
		return (maxlink);
	if (i == 1)
		return (maxsize);
	else
		return (maxgroup);
}

t_list		*ft_spacelink(t_list *rep, int a)
{
	t_list		tmp;
	size_t		j;
	size_t		k;
	size_t		max;
	char		*buf;

	tmp = ft_lstgetfirst(rep);
	max = ft_getmaxlen(rep, 0, a);
	while (tmp != NULL)
	{
		if (ft_strlen(tmp.content->itoardlink) < max)
		{
			k = 0;
			j = max - (ft_strlen(tmp.content->itoardlink));
			buf = ft_strnew(j);
			while (k < j)
			{
				buf[k] = ' ';
				k++;
			}
			tmp.content->itoardlink = ft_strjoin(buf, tmp.content->itoardlink);
		}
		tmp = tmp->next;
	}
	return (tmp);
}

t_list		*ft_spacesize(t_list *rep, int a)
{
	t_list		*tmp;
	size_t		j;
	size_t		k;
	size_t		max;
	char		*buf;

	max = ft_getmaxlen(rep, 1, a) + ft_getidlen(dir, 0, a) + 1;
	tmp = ft_lstgetfirst(rep);
	while (tmp != NULL)
	{
		if (ft_strlen(tmp.content->size) < max && ft_strlen(tmp.content->size) != 0)
		{
			k = 0;
			j = max - (ft_strlen(tmp.content->size));
			buf = ft_strnew(j);
			while (k < j)
			{
				buf[k] = ' ';
				k++;
			}
			tmp.content->size = ft_strjoin(buf, tmp.content->size);
		}
		tmp = tmp->next;
	}
	return (tmp);
}

t_list		*ft_spacegroup(t_list *rep, int a)
{
	t_list		*tmp;
	size_t		j;
	size_t		k;
	size_t		max;
	char		*buf;

	max = ft_getmaxlen(rep, 2, a);
	tmp = ft_lstgetfirst(rep);
	while (tmp != NULL)
	{
		if (ft_strlen(tmp.content->group) < max && ft_strlen(tmp.content->group) != 0)
		{
			k = 0;
			j = max - (ft_strlen(tmp.content->group));
			buf = ft_strnew(j);
			while (k < j)
			{
				buf[k] = ' ';
				k++;
			}
			tmp.content->group = ft_strjoin(buf, tmp.content->group);
		}
		tmp = tmp->next;
	}
	return (tmp);
}