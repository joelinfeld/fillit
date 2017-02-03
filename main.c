/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 09:57:03 by bchin             #+#    #+#             */
/*   Updated: 2017/02/03 15:46:14 by bchin            ###   ########.fr       */
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
	int		j;

	i = 0;
	if (argc == 2)
	{
		str = split_me(fill_array(argv[1]));
		while (str[i] != '\0')
		{
			ptr = find_hash(str[i]);
			j = index_score(ptr);
			printf("%d\n", j);
			ft_putstr(str[i]);
			i++;
		}
	}
	return (0);
}
