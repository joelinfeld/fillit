/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:04:13 by jinfeld           #+#    #+#             */
/*   Updated: 2017/02/23 22:07:49 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fillit.h"
#include <string.h>

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
static int codebreak(char **sq, tet p, char *bp, int x, int y)
{
	if (sq[x][y] == '.')
		sq[x][y] = p.alpha;
	else return (0);
	if (*bp == '\0')
		return (1);
	if (*bp == '1')
	{
		if (codebreak(sq, p, bp + 1, x, y + 1))
			return (1);
	}
	if (*bp == 'n')
	{
		if (codebreak(sq, p, bp + 1, x + 1, y))
			return (1);
	}
	if (*bp == '-')
	{
		if (codebreak(sq, p, bp + 1, x + 1, y - 1))
			return (1);
	}
	if (*bp == '+')
	{
		if (codebreak(sq, p, bp + 1, x + 1, y + 1))
			return (1);
	}
	if (*bp == '3')
	{
		if (codebreak(sq, p, bp + 1, x + 1, y - 2))
			return (1);
	}
	sq[x][y] = '.';
	return (0);
}

static int nearestsq(int nb)
{
	if (!ft_sqrt(nb, nb))
		return(nearestsq(nb + 1));
	else
		return(ft_sqrt(nb, nb));
	return (0);
}

char	**blanksq(int size)
{
	int		sz;
	int		i;
	int		j;
	char	**sq;
	
	sz = nearestsq(size);
	printf("sz:%d\n", sz);
	sq = (char**)malloc(sizeof(char*) * sz + 1);
	i = 0;
	while (i < sz)
	{
		sq[i] = (char *)malloc(sizeof(char) * sz + 1);
		i++;
	}
	sq[i] = NULL;
	i = 0;
	while (i < sz && sq[i])
	{
		j = 0;
		while (j < sz)
		{
			sq[i][j++] = '.';
		}
		sq[i][j] = '\0';
//		ft_putstr(sq[i]);
//		write(1, "\n", 1);
		i++;
	}
	return (sq);
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

static int	fit(char **sq, tet *p, int nm)
{
	int x;
	int y;
	int i;
	
	x = 0;
	y = 0;
	i = nextshape(p) - 1;
	if (!nextshape(p))
		return(1);
	while (x < nm)
	{
		while (sq[x][y])
		{
			if (sq[x][y] == '.' && codebreak(sq, p[i], p[i].bp, x, y))
			{
				p[i].use = 1;
				if (fit(sq, p, nm))
					return (1);
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

	sqz = ft_sqrt(sz, sz);
	sq = blanksq(sz);
	if(!fit(sq, p, nm))
		fillit(p, nm, sz + 1);
	printsq(sq);
}
