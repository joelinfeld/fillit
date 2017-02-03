/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 19:41:32 by bchin             #+#    #+#             */
/*   Updated: 2017/02/02 19:52:03 by bchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*fill_array(char *argv)
{
	int		ret;
	int		fd;
	char	buf[1];
	int		*array;
	int		pieces;

	pieces = count_shapes(argv);
	fd = open(argv, O_RDONLY);
	array = (int *)malloc(sizeof(int) * (pieces + 1));
	if (fd == -1)
	{
		write(2, "ope() error!", 13);
		return (1);
	}
	while ((ret = read(fd, buf, 1)))
	{
		if (ret < 0)
		{
			write(2, "read() error!", 13);
			return (1);
		}
		array[pieces] = \0';
		*array++ = *buf++;
	}
	if (close(fd) == -1)
	{
		write(2, "close() error!", 13);
		return (1);
	}
	return (array);
}
