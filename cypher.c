/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cypher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 11:56:38 by jinfeld           #+#    #+#             */
/*   Updated: 2017/03/16 17:39:14 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	cypher(char *str, char *bp)
{
	int hashi;
	int j;
	int i;

	i = 0;
	j = 0;
	hashi = -1;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (i - hashi == 1 && hashi != -1)
				bp[j++] = '1';
			if (i - hashi == 3)
				bp[j++] = '3';
			if (i - hashi == 4)
				bp[j++] = '-';
			if (i - hashi == 5)
				bp[j++] = 'n';
			if (i - hashi == 6)
				bp[j++] = '+';
			hashi = i;
		}
		i++;
	}
}

t_tet		maketet(char *str, int i)
{
	t_tet	ret;
	int		width;

	width = 0;
	if (!(ret.bp = ft_memalloc(5)))
		return (ret);
	cypher(str, ret.bp);
	ret.bp[ft_strlen(ret.bp)] = '\0';
	ret.alpha = 'A' + i;
	ret.use = 0;
	return (ret);
}

t_num		makenum(int x, int y, int sz)
{
	t_num ret;

	ret.x = x;
	ret.y = y;
	ret.sz = sz;
	return (ret);
}
