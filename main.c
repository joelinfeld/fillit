/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 09:57:03 by bchin             #+#    #+#             */
/*   Updated: 2017/02/23 22:03:18 by jinfeld          ###   ########.fr       */
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


int		main(int argc, char **argv)
{
	char	**str;
	char	*ptr; 
	int		i;
	tet		*p;
	int sz;
	
	sz = 3 * 4;
	i = 0;
	if (argc == 2)
	{
		str = split_me(fill_array(argv[1]));
		//if(!(p = (tet*)malloc(sizeof(tet) * count_pieces(argv[1]))))
		if(!(p = (tet*)malloc(sizeof(tet) * 20)))
			return (0);
		while (str[i] != '\0')
		{
			ptr = find_hash(str[i]); //points to first hash in str[i]
			printf("index sum:%d\nindex max:%d\nconnections%d\n", index_score(ptr), last_index(ptr), connections(str[i]));
			p[i] = maketet(ptr, i);
			printf("cypher:%s\n", p[i].bp);
			printf("%s", str[i]);
			i++;
		}
		p[3].bp = "STOP";
		fillit(p, 3, sz);
	}
	return (0);
}
