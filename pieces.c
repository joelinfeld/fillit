/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:52:03 by bchin             #+#    #+#             */
/*   Updated: 2017/02/28 22:53:40 by bchin            ###   ########.fr       */
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
			return(0);
		if (str[i] == '#')
			hash++;
		i++;
	}
	if (hash != 4)
		return (0);
	return(1);
}

int		connections(char *str)
{
	int i;
	int j;
	int	k;

	i = 0;
	j = 0;
	k = strlen(str);
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

int		check_count(char *file)
{
	int		i;

	i = count_length(file);
	if (((i - 20) % 21) != 0)
		return (0);
	return (1);
}

//int		check_piece_count(char **str)
//{
//	int i;
//	int j;
//
//	i = 0;
//	j = 0;
//	while (str[j])
//	{
//		while (str[j][i])
//		{
//			if (char_is_dot(str[j][i]) == 1
//			&& i - 2 > 0
//			&& char_is_newline(str[j][i + 1]) == 1
//			&& (char_is_newline(str[j][i + 2]) == 1 || str[i + 2] == '\0'))
//			{
//				if (i < 17)
//					return (0);
//			}
//			i++;
//		}
//		j++;
//	}
//	return (1);
//}

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
		i++;
	}
	return (1);
}
