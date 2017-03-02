/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codebreak.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 19:21:58 by jinfeld           #+#    #+#             */
/*   Updated: 2017/03/02 15:42:55 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		pdelete(char **sq, tet p, char *bp, num nums)
{
	sq[nums.x][nums.y] = '.';
	if (*bp == '1' && nums.y++ >= 0)
		pdelete(sq, p, bp + 1, nums);
	if (*bp == 'n' && nums.x++ >= 0)
		pdelete(sq, p, bp + 1, nums);
	if (*bp == '-' && nums.x++ >= 0 && nums.y-- >= 0)
		pdelete(sq, p, bp + 1, nums);
	if (*bp == '+' && nums.x++ >= 0 && nums.y++ >= 0)
		pdelete(sq, p, bp + 1, nums);
	if (*bp == '3' && nums.x++ >= 0)
	{
		nums.y -= 2;
		pdelete(sq, p, bp + 1, nums);
	}
}

static int	cheatsheet(char **sq, tet p, char *bp, num nums)
{
	if (*bp == '1' && nums.sz - nums.y++ >= 2)
		if (codebreak(sq, p, bp + 1, nums))
			return (1);
	if (*bp == 'n' && nums.sz - nums.x++ >= 2)
		if (codebreak(sq, p, bp + 1, nums))
			return (1);
	if (*bp == '-' && nums.y-- - 1 >= 0 && nums.sz - nums.x++ >= 2)
		if (codebreak(sq, p, bp + 1, nums))
			return (1);
	if (*bp == '+' && nums.sz - nums.y++ >= 2 && nums.sz - nums.x++ >= 2)
		if (codebreak(sq, p, bp + 1, nums))
			return (1);
	if (*bp == '3' && nums.y - 2 >= 0 && nums.sz - nums.x++ >= 2)
	{
		nums.y -= 2;
		if (codebreak(sq, p, bp + 1, nums))
			return (1);
	}
	return (0);
}

int			codebreak(char **sq, tet p, char *bp, num nums)
{
	if (sq[nums.x][nums.y] == '.')
		sq[nums.x][nums.y] = p.alpha;
	else
		return (0);
	if (*bp == '\0')
		return (1);
	if (!cheatsheet(sq, p, bp, nums))
	{
		sq[nums.x][nums.y] = '.';
		return (0);
	}
	return (1);
}
