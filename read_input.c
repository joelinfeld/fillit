/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 21:13:06 by jinfeld           #+#    #+#             */
/*   Updated: 2017/01/31 14:07:33 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_shapes(char *argv)
{
	int ret;
	int fd;
	char buf[21];

	fd = open(argv, O_RDONLY);
	if	(fd == -1)
	{
		write(2, "open() error!", 13);
			return (1);
	}
	while ((ret = read(fd, buf, 21)))
	{
		if (ret < 0)
		{
			write(2, "read() error!", 13);
			return (1);
		}
		push_node(begin_list, tail_list, buf[0]);
	}
	if (close(fd) == -1)
	{
		write(2, "close() error!", 13);
		return (1);
	}
	return (0);
}
