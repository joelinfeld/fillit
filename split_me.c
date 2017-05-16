/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:13:30 by bchin             #+#    #+#             */
/*   Updated: 2017/03/02 18:12:21 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		write_piece(char *dest, char *from)
{
	int i;

	i = 0;
	while (i < 20)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

int			count_pieces(char *str)
{
	int	i;
	int j;
	int	pieces;

	pieces = 0;
	i = 0;
	j = ft_strlen(str);
	while (str[i] != '\0')
	{
		if (j - i > 1
			&& char_is_dot(str[i]) == 1
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
	int	k;
	int	piece;

	piece = 0;
	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		split[piece] = (char*)malloc(sizeof(char) * 21);
		if (split)
		{
			write_piece(split[piece], &str[i]);
			piece++;
		}
		i++;
		while (i % 21 != 0 && str[i] != '\0')
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
