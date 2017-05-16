/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 19:41:32 by bchin             #+#    #+#             */
/*   Updated: 2017/03/02 17:25:11 by bchin            ###   ########.fr       */
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

	index = 0;
	fd = open(argv, O_RDONLY);
	if (!(array = (char *)malloc(sizeof(char) * (count_length(argv) + 1))))
		return (NULL);
	if (fd == -1)
		return (0);
	while ((ret = read(fd, &buf, 1)))
	{
		if (ret < 0)
			return (0);
		array[index] = buf[0];
		index++;
	}
	array[index] = '\0';
	if (close(fd) == -1)
		return (0);
	return (array);
}
