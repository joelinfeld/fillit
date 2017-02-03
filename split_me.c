/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:13:30 by bchin             #+#    #+#             */
/*   Updated: 2017/02/03 12:35:45 by bchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			char_is_newline(char a)
{
	if (a == '\n')
		return (1);
	return (0);
}

int			char_is_dot(char a)
{
	if (a == '.')
		return (1);
	return (0);
}

void		write_piece(char *dest, char *from)
{
	int i;

	i = 0;
	while (i < 21)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

int			count_pieces(char *str)
{
	int	i;
	int	pieces;

	pieces = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (char_is_dot(str[i]) == 1
		&& char_is_newline(str[i + 1]) == 1
		&& (char_is_newline(str[i + 2]) == 1 || str[i + 2] == '\0'))
			pieces++;
		i++;
	}
	return (pieces);
}

void		write_split(char **split, char *str)
{
	int	i;
	int k;
	int	piece;

	piece = 0;
	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		split[piece] = (char*)malloc(sizeof(char) * 22);
		if (split)
		{
			write_piece(split[piece], &str[i]);
			piece++;
		}
		i++;
		while (i % 21 != 0)
			i++;
	}
}

char		**split_me(char *str)
{
	char	**split;
	int		pieces;

	if (!str)
		return (NULL);
	pieces = count_pieces(str);
	split = (char **)malloc(sizeof(char*) * (pieces + 1));
	if (split == NULL)
		return (NULL);
	split[pieces] = 0;
	write_split(split, str);
	return (split);
}
