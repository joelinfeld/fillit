/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 19:26:08 by jinfeld           #+#    #+#             */
/*   Updated: 2017/02/28 21:45:38 by jinfeld          ###   ########.fr       */
/*   Updated: 2017/02/28 21:05:49 by bchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_sqrt(int nb, int cap)
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

int			nearestsq(int nb)
{
	if (!ft_sqrt(nb, nb))
		return (nearestsq(nb + 1));
	else
		return (ft_sqrt(nb, nb));
	return (0);
}

char		**blanksq(int size)
{
	int		i;
	int		j;
	char	**sq;

	if (!(sq = (char**)malloc(sizeof(char*) * size + 1)))
		return (0);
	i = 0;
	while (i < size)
	{
		if (!(sq[i] = (char *)malloc(sizeof(char) * size + 1)))
			return (0);
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
		sq[i++][j] = '\0';
	}
	return (sq);
}
