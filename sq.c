/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 19:26:08 by jinfeld           #+#    #+#             */
/*   Updated: 2017/02/28 19:27:17 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int nearestsq(int nb)
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
		i++;
	}
	return (sq);
}

