/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 19:27:21 by bchin             #+#    #+#             */
/*   Updated: 2017/02/28 19:29:18 by bchin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			char_is_newline(char a)
{
	if (a == '\n')
		return (1);
	return (0);
}

int			char_is_dot(char a)
{
	if (a == '.' || a == '#')
		return (1);
	return (0);
}
