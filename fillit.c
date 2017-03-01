/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:04:13 by jinfeld           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/02/28 19:30:21 by jinfeld          ###   ########.fr       */
=======
/*   Updated: 2017/02/28 19:07:25 by bchin            ###   ########.fr       */
>>>>>>> 25796212bfc24d15c8d19bad444637d51a9ec5fa
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int ft_sqrt(int nb, int cap)
{
	if (nb < 0)
		return (0);
	if (nb * nb != cap)
		return (ft_sqrt(nb - 1, cap));
	if (nb * nb == cap)
		return (nb);
	else 
		return (0);
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
}
