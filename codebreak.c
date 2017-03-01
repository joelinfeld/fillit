/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codebreak.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 19:21:58 by jinfeld           #+#    #+#             */
/*   Updated: 2017/02/28 19:41:07 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		pdelete(char **sq, tet p, char *bp, int x, int y)
{
	sq[x][y] = '.';
	if (*bp == '1')
		pdelete(sq, p, bp + 1, x, y + 1);
	if (*bp == 'n')
		pdelete(sq, p, bp + 1, x + 1, y);
	if (*bp == '-')
		pdelete(sq, p, bp + 1, x + 1, y - 1);
	if (*bp == '+')
		pdelete(sq, p, bp + 1, x + 1, y + 1);
	if (*bp == '3')
		pdelete(sq, p, bp + 1, x + 1, y - 2);
}

static int cheatsheet(char **sq, tet p, char *bp, int x, int y, int sz)
{
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
	return(0);
}

int codebreak(char **sq, tet p, char *bp, int x, int y, int sz)
{
	if (sq[x][y] == '.')
		sq[x][y] = p.alpha;
	else 
		return (0);
	if (*bp == '\0')
		return (1);
	if(!cheatsheet(sq, p, bp, x, y, sz))
	{
		sq[x][y] = '.';
		return (0);
	}
	return (1);
}
