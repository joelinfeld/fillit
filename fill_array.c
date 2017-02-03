/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 19:41:32 by bchin             #+#    #+#             */
/*   Updated: 2017/02/03 10:40:13 by bchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*fill_array(char *argv)
{
	int		ret;
	int		fd;
	char	buf[1];
	char	*array;
	int		index;

	index = 0;;
	fd = open(argv, O_RDONLY);
	array = (char *)malloc(sizeof(char) * (count_length(argv) + 1));
	if (fd == -1)
	{
		write(2, "ope() error!", 13);
		return (NULL);
	}
	while ((ret = read(fd, &buf, 1)))
	{
		if (ret < 0)
		{
			write(2, "read() error!", 13);
			return (NULL);
		}
		array[index] = buf[0];
		index++;
	}
	array[index] = '\0';
	if (close(fd) == -1)
	{
		write(2, "close() error!", 13);
		return (NULL);
	}
	return (array);
}
