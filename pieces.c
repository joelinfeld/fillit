/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:52:03 by bchin             #+#    #+#             */
/*   Updated: 2017/03/02 18:29:39 by jinfeld          ###   ########.fr       */
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

int		char_check(char *str)
{
	int hash;
	int i;

	i = 0;
	hash = 0;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (0);
		if (str[i] == '#')
			hash++;
		i++;
	}
	if (hash != 4)
		return (0);
	return (1);
}

int		connections(char *str)
{
	int i;
	int j;
	int	k;

	i = 0;
	j = 0;
	k = ft_strlen(str);
	while (str[i] != '\0')
	{
		if ((k - i > 1) && str[i] == '#' && str[i + 1] == '#')
			j++;
		if ((k - i > 5) && str[i] == '#' && str[i + 5] == '#')
			j++;
		if ((i - 1 >= 0) && str[i] == '#' && str[i - 1] == '#')
			j++;
		if ((i - 5 >= 0) && str[i] == '#' && str[i - 5] == '#')
			j++;
		i++;
	}
	return (j);
}

int		check_newlines(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			j++;
		i++;
	}
	return (j);
}

int		check_errors(char **str, int pieces)
{
	int i;

	i = 0;
	while (i < pieces)
	{
		if (connections(str[i]) != 6 && connections(str[i]) != 8)
			return (0);
		if (!char_check(str[i]))
			return (0);
		if (check_newlines(str[i]) != 4)
			return (0);
		i++;
	}
	return (1);
}
