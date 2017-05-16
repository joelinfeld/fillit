/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinfeld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:59:05 by jinfeld           #+#    #+#             */
/*   Updated: 2017/03/09 18:29:46 by jinfeld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	printsq(char **sq)
{
	int i;

	i = 0;
	while (sq[i])
	{
		ft_putstr(sq[i++]);
		write(1, "\n", 1);
	}
}

int			nextshape(t_tet *p)
{
	int i;

	i = 0;
	while (ft_strcmp(p[i].bp, "STOP"))
	{
		if (p[i].use == 1)
			i++;
		else
			return (i + 1);
	}
	return (0);
}

static int	fit(char **sq, t_tet *p, t_num nums)
{
	int i;

	nums.x = 0;
	i = nextshape(p) - 1;
	if (!nextshape(p))
		return (1);
	while (nums.x < nums.sz)
	{
		nums.y = 0;
		while (sq[nums.x][nums.y] && nums.x < nums.sz)
		{
			if (sq[nums.x][nums.y] == '.' && codebreak(sq, p[i], p[i].bp, nums))
			{
				p[i].use = 1;
				if (fit(sq, p, nums))
					return (1);
				pdelete(sq, p[i], p[i].bp, nums);
				p[i].use = 0;
			}
			nums.y++;
		}
		nums.x++;
	}
	return (0);
}

void		fillit(t_tet *p, int nm, int sz)
{
	int		sqz;
	char	**sq;
	int		sqd;
	t_num	nums;

	nums = makenum(0, 0, 0);
	sqz = nearestsq(sz);
	nums.sz = sqz;
	sq = blanksq(sqz);
	sqd = (sqz + 1) * (sqz + 1);
	if (!fit(sq, p, nums))
	{
		arrdel(sq);
		fillit(p, nm, sqd);
	}
	else
	{
		printsq(sq);
		arrdel(sq);
	}
}
