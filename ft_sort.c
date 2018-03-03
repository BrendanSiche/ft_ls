/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiche <bsiche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 23:24:26 by bsiche            #+#    #+#             */
/*   Updated: 2018/03/02 02:06:00 by bsiche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_lexico(t_lstcontainer *liste)
{
	t_ls	*tmp;
	t_ls	*tmp2;
	int 	i;
	int		j;

	liste->firstelement = ft_lstgetfirst(liste->firstelement);
	while(liste->firstelement != NULL)
	{
		i = liste->firstelement->index;
		tmp = liste->firstelement->content;
		if (liste->firstelement->next != NULL)
		{
			tmp2 = liste->firstelement->next->content;
			j = liste->firstelement->next->index;
		}
		if ((ft_strcmp(tmp->name, tmp2->name) > 0))
		{
			ft_lstswap(liste->firstelement, i, j);
			liste->firstelement = ft_lstgetfirst(liste->firstelement);
		}
		if (liste->firstelement->next != NULL)
			liste->firstelement = liste->firstelement->next;
		else
		{
			liste->firstelement = ft_lstgetfirst(liste->firstelement);
			break;
		}
	}
}

void	ft_timesort(t_lstcontainer *liste)
{
	t_ls	*tmp;
	t_ls	*tmp2;
	int 	i;
	int		j;

	liste->firstelement = ft_lstgetfirst(liste->firstelement);
	while(liste->firstelement != NULL)
	{
		i = liste->firstelement->index;
		tmp = liste->firstelement->content;
		if (liste->firstelement->next != NULL)
		{
			tmp2 = liste->firstelement->next->content;
			j = liste->firstelement->next->index;
		}
		if (tmp->epoch < (tmp2->epoch))
		{
			ft_lstswap(liste->firstelement, i, j);
			liste->firstelement = ft_lstgetfirst(liste->firstelement);
		}
		if (liste->firstelement->next != NULL)
			liste->firstelement = liste->firstelement->next;
		else
			break;
	}
}

void	ft_sizesort(t_lstcontainer *liste)
{
	t_ls	*tmp;
	t_ls	*tmp2;
	int 	i;
	int		j;

	liste->firstelement = ft_lstgetfirst(liste->firstelement);
	while(liste->firstelement != NULL)
	{
		i = liste->firstelement->index;
		tmp = liste->firstelement->content;
		if (liste->firstelement->next != NULL)
		{
			tmp2 = liste->firstelement->next->content;
			j = liste->firstelement->next->index;
		}
		if (ft_atoi(tmp->size) < ft_atoi(tmp2->size))
		{
			ft_lstswap(liste->firstelement, i, j);
			liste->firstelement = ft_lstgetfirst(liste->firstelement);
		}
		if (liste->firstelement->next != NULL)
			liste->firstelement = liste->firstelement->next;
		else
			break;
	}
}