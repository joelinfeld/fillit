/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:04:13 by jinfeld           #+#    #+#             */
/*   Updated: 2017/02/09 19:53:35 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fillit.h"

static void	blanksq(char **sq, int size)
{
	
}

static int	fit(char **sq, tet p)
{
	int i;
	int j;
	char *bp;

	bp = p.bp;
	i = 0;
	j = 0;

	while (sq[i][j] != \n)
	{
		if (sq[i][j] == '.')
		{
			
		}
	}
}

void		fillit(tet	*p, int sz)
{
	int		minsize;
	char	**sq;
	int i;
	int j;

	i = 0;
	j = 0;
	minsize = sz * 4;
	blanksq(sq, minsize);
	while (i < size)
	{
		if(!fit(p[i]))
			i++;
	}
	
}
