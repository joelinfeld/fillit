/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 19:32:30 by bchin             #+#    #+#             */
/*   Updated: 2017/02/03 10:23:27 by bchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		piece_cmp(char *big, char *little)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (big[i] != '\0')
	{
		while (big[i + j] == little[j])
		{
			if (little[j + i] == '\0')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
