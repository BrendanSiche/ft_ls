/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiche <bsiche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 05:05:46 by bsiche            #+#    #+#             */
/*   Updated: 2018/02/28 19:20:04 by bsiche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

int		ft_hidden(t_lstcontainer *liste)
{
	t_ls		*buf;
	int			i;

	i = 0;
	liste->firstelement = ft_lstgetfirst(liste->firstelement);
	while (liste->firstelement != NULL)
	{
		buf = liste->firstelement->content;
		if (buf->name[0] == '.')
			i++;
		if (liste->firstelement->next != NULL)
			liste->firstelement = liste->firstelement->next;
		else
			break ;
	}
	return (i);
}