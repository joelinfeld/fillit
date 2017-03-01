/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:04:13 by jinfeld           #+#    #+#             */
/*   Updated: 2017/02/28 17:49:05 by jinfeld          ###   ########.fr       */
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

void		delete(char **sq, tet p, char *bp, int x, int y)
{
	sq[x][y] = '.';
	if (*bp == '1')
		delete(sq, p, bp + 1, x, y + 1);
	if (*bp == 'n')
		delete(sq, p, bp + 1, x + 1, y);
	if (*bp == '-')
		delete(sq, p, bp + 1, x + 1, y - 1);
	if (*bp == '+')
		delete(sq, p, bp + 1, x + 1, y + 1);
	if (*bp == '3')
		delete(sq, p, bp + 1, x + 1, y - 2);
}

static int codebreak(char **sq, tet p, char *bp, int x, int y, int sz)
{
	if (sq[x][y] == '.')
		sq[x][y] = p.alpha;
	else 
		return (0);
	if (*bp == '\0')
		return (1);
	if (*bp == '1' && sz - y >= 2)
	{
		if (codebreak(sq, p, bp + 1, x, y + 1, sz))
			return (1);
	}
	if (*bp == 'n' && sz - x >= 2)
	{
		if (codebreak(sq, p, bp + 1, x + 1, y, sz))
			return (1);
	}
	if (*bp == '-' && y - 1 >= 0 && sz - x >= 2)
	{
		if (codebreak(sq, p, bp + 1, x + 1, y - 1, sz))
			return (1);
	}
	if (*bp == '+' && sz - y >= 2 && sz - x >= 2)
	{
		if (codebreak(sq, p, bp + 1, x + 1, y + 1, sz))
			return (1);
	}
	if (*bp == '3' && y - 2 >= 0 && sz - x >= 2)
	{
		if (codebreak(sq, p, bp + 1, x + 1, y - 2, sz))
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
	int		i;
	int		j;
	char	**sq;
	
	printf("sz:%d\n", size);
	if (!(sq = (char**)malloc(sizeof(char*) * size + 1)))
		return(0);
	i = 0;
	while (i < size)
	{
		if(!(sq[i] = (char *)malloc(sizeof(char) * size + 1)))
			return(0);
		i++;
	}
	sq[i] = NULL;
	i = 0;
	while (i < size && sq[i])
	{
		j = 0;
		while (j < size)
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

static int	fit(char **sq, tet *p, int sz)
{
	int x;
	int y;
	int i;
	
	x = 0;
	write(1, "1\n", 2);
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
				write(1, "2\n", 2);
				if (fit(sq, p, sz))
					return (1);
				delete(sq, p[i], p[i].bp, x, y);
				p[i].use = 0;
			}
			write(1, "4", 1);
			y++;
		}
		write(1, "3", 1);
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
