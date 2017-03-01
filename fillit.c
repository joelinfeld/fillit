/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:04:13 by jinfeld           #+#    #+#             */
/*   Updated: 2017/02/28 19:46:42 by jinfeld          ###   ########.fr       */
/*   Updated: 2017/02/28 19:07:25 by bchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void printsq(char **sq)
{
	int i;

	i = 0;
	while(sq[i])
	{
		ft_putstr(sq[i++]);
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
}

int		nextshape(tet *p)
{
	int i;

	i = 0;
	while (strcmp(p[i].bp, "STOP"))
	{
		if (p[i].use == 1)
			i++;
		else
			return (i + 1);
	}
	return(0);
}

static int	fit(char **sq, tet *p, int sz)
{
	int x;
	int y;
	int i;
	
	x = 0;
	i = nextshape(p) - 1;
	if (!nextshape(p))
		return(1);
	while (x < sz)
	{
		y = 0;
		while (sq[x][y])
		{
			if (sq[x][y] == '.' && codebreak(sq, p[i], p[i].bp, x, y, sz))
			{
				p[i].use = 1;
				if (fit(sq, p, sz))
					return (1);
				pdelete(sq, p[i], p[i].bp, x, y);
				p[i].use = 0;
			}
			y++;
		}
		x++;
	}
	return(0);
}

void	fillit(tet *p, int nm, int sz)
{
	int		sqz;
	char	**sq;

	sqz = nearestsq(sz);
	sq = blanksq(sqz);
	if(!fit(sq, p, sqz))
		fillit(p, nm, sz + 1);
	else
		printsq(sq);
}
