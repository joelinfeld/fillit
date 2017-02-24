/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cypher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 11:56:38 by jinfeld           #+#    #+#             */
/*   Updated: 2017/02/23 20:33:41 by jinfeld          ###   ########.fr       */
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
			if(i - hashi == 1 && hashi != -1)
				bp[j++] = '1';
			if(i - hashi == 3)
				bp[j++] = '3';
			if(i - hashi == 4)
				bp[j++] = '-';
			if(i - hashi == 5)
				bp[j++] = 'n';
			if(i - hashi == 6)
				bp[j++] = '+';
			hashi = i;
		}
		i++;
	}
	bp[j] = '\0';
}
static int	weed(char *str)
{
	int w;
	int count;
	int i;

	count = 0;
	w = 0;
	i = 0;
	while(str[i])
	{
		if (str[i] == '#')
			count++;
		if (str[i] == '\n')
		{
			if (count > w)
				w = count;
			count = 0;
		}
		i++;
	}
	return (w);
}
tet		maketet(char *str, int i)
{
	tet		ret;
	int		width;
	
	width = 0;
	//if(!(ret = (tet)malloc(sizeof(tet))))
	//	return (ret);
	if(!(ret.bp = ft_memalloc(5)))
		return (ret);
	cypher(str, ret.bp);
	ret.w = weed(str);
	ret.alpha = 'A' + i;
	ret.use = 0;
	return (ret);
}
