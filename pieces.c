/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:52:03 by bchin             #+#    #+#             */
/*   Updated: 2017/02/03 15:37:37 by bchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*find_hash(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			break ;
		i++;
	}
	return (&str[i]);
}

int		index_score(char *str)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			j += i;
		i++;
	}
	return (j);
}
