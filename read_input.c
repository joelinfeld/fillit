/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 21:13:06 by jinfeld           #+#    #+#             */
/*   Updated: 2017/03/09 17:39:20 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_shapes(char *argv)
{
	int		ret;
	int		fd;
	int		i;
	char	buf[21];

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((ret = read(fd, buf, 21)))
	{
		if (ret < 0)
			return (0);
		i++;
	}
	if (close(fd) == -1)
		return (0);
	return (i);
}

int		count_length(char *argv)
{
	int		ret;
	int		fd;
	int		i;
	char	buf[1];

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((ret = read(fd, buf, 1)))
	{
		if (ret < 0)
			return (0);
		i++;
	}
	if (close(fd) == 1)
		return (0);
	return (i);
}
