/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 09:57:03 by bchin             #+#    #+#             */
/*   Updated: 2017/02/28 19:39:34 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
}

static int		shapes(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void printsq(char **sq)
{
	int i;

	i = 0;
	while(sq[i])
	{
		ft_putstr(sq[i++]);
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	char	**str;
	char	*ptr; 
	int		i;
	tet		*p;
	int		sz;
	
	i = 0;
	if (argc == 2)
	{
		str = split_me(fill_array(argv[1]));
		sz = shapes(str) * 4;
		if(!(p = (tet*)malloc(sizeof(tet) * shapes(str) + 1)))
			return (0);
		while (str[i] != '\0')
		{
			ptr = find_hash(str[i]);
			p[i] = maketet(ptr, i);
			i++;
		}
		p[shapes(str)].bp = "STOP";
		fillit(p, shapes(str), sz);
		printsq(sq);
	}
	return (0);
}
