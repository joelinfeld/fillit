/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:04:13 by jinfeld           #+#    #+#             */
/*   Updated: 2017/02/23 18:44:56 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fillit.h"
static int ft_sqrt(int nb, int cap)
{
	if (nb = 0)
		return (0);
	if (nb * nb != cap)
		return (ft_sqrt(nb - 1, cap));
	if (nb * nb == cap)
		return (nb);
	else return (0);
}

static int codebreak(char **sq, char *bp, int x, int y)
{
	if (bp == '\0')
		return (1);
	if (sq[x][y] == '.')
		sq[x][y] = '#';
	else
		return (0);
	if (bp == '1')
		codebreak(sq, ++bp, x, y + 1);
	if (bp == 'n')
		codebreak(sq, ++bp, x + 1, y);
	if (bp == '-')
		codebreak(sq, ++bp, x + 1, y - 1);
	if (bp == '+')
		codebreak(sq, ++bp, x + 1, y + 1);
	if (bp == '3')
		codebreak(sq, ++bp, x + 1, y - 2);
	sq[x][y] = '.';
}

static int nearestsq(int nb)
{
	if (!ft_sqrt(nb, nb))
		ft_sqrt(nb + 1, nb + 1);
	else
		return(ft_sqrt(nb, nb));
}

static void	blanksq(char **sq, int size)
{
	int sz;
	int i;
	int j;

	sz = nearestsq(size);
	sq = (char**)(ft_memalloc(sz))
	i = 0;
	while (i < sz)
		sq[i++] = (char *)(ft_memalloc(sz + 1));
	sq[i] = NULL;
	i = 0;
	while (i < size && s[i])
	{
		j = 0;
		while (j < size)
		{
			sq[i][j++] = '.';
		}
		sq[i][j] = '\0';
		i++;
	}
}

static int	fit(char **sq, tet 	*p, int nm)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	if (!nextshape(p))
		return(1);
	while (x < nm)
	{
		while (sq[x][y])
		{
			if (sq[x][y] == '.' && codebreak(sq, *p, x, y))
			{
				if (fit(sq, p, nm))
					return (1);
			}
			y++;
		}
		x++;
	}
	return(0);
}

char	**fillit(tet *p, int nm, int sz)
{
	char	**sq;
	blanksq(sq, sz);
	if(!fit(sq, p, nm))
		fillit(p, nm, sz + 1)
	return(sq);
}
