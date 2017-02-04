/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 09:57:03 by bchin             #+#    #+#             */
/*   Updated: 2017/02/03 16:04:04 by bchin            ###   ########.fr       */
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

	i = 0;
	if (argc == 2)
	{
		str = split_me(fill_array(argv[1]));
		while (str[i] != '\0')
		{
			ptr = find_hash(str[i]); //points to first hash in str[i]
			printf("index sum:%d\nmax index:%d\n", index_score(ptr), last_index(ptr));
			printf("%s", str[i]);
			i++;
		}
	}
	return (0);
}
