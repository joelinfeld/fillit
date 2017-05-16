/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 09:57:03 by bchin             #+#    #+#             */
/*   Updated: 2017/03/09 19:11:34 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <unistd.h>

void			ft_putstr(const char *str)
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

static void		mrlist(char **str, t_tet *p)
{
	int		i;
	char	*ptr;

	i = 0;
	while (str[i] != '\0')
	{
		ptr = find_hash(str[i]);
		p[i] = maketet(ptr, i);
		i++;
	}
	p[shapes(str)].bp = "STOP";
}

void			error(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

int				main(int argc, char **argv)
{
	char	**str;
	t_tet	*p;
	int		sz;

	if (argc == 2)
	{
		if (!check_count(argv[1]))
			error("error");
		str = split_me(fill_array(argv[1]));
		if (!check_errors(str, shapes(str)))
		{
			arrdel(str);
			error("error");
		}
		sz = shapes(str);
		if (!(p = (t_tet*)malloc(sizeof(t_tet) * sz + 1)))
			return (0);
		mrlist(str, p);
		arrdel(str);
		fillit(p, sz, sz * 4);
		pdel(&p);
	}
	else
		error("invalid number of arguments.\nusage: ./fillit [filename]");
	return (0);
}
