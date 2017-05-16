/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:06:05 by jinfeld           #+#    #+#             */
/*   Updated: 2017/03/09 19:11:59 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	arrdel(char **sq)
{
	int i;

	i = 0;
	while (sq[i])
		ft_strdel(&sq[i++]);
	ft_memdel((void**)sq);
}

void	pdel(t_tet **p)
{
	int i;

	i = 0;
	while (!ft_strcmp(p[i]->bp, "STOP"))
		ft_strdel(&p[i++]->bp);
	ft_strdel(&p[i]->bp);
	ft_memdel((void**)p);
}
