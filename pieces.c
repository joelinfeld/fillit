/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:52:03 by bchin             #+#    #+#             */
/*   Updated: 2017/02/03 16:33:29 by bchin            ###   ########.fr       */
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

int		last_index(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (i >= 0 && str[i] != '#')
		i--;
	return (i);

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

int		connections(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#' && str[i + 1] == '#')
			j++;
		if (str[i] == '#' && str[i + 5] == '#')
			j++;
		if (str[i] == '#' && str[i - 1] == '#')
			j++;
		if (str[i] == '#' && str[i - 5] == '#')
			j++;
		i++;
	}
	return (j);
}
