/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:21:06 by apruvost          #+#    #+#             */
/*   Updated: 2017/12/09 20:05:37 by fdrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "./libft/libft.h"

static int		ft_testsq(t_square *sol, t_tetri *tet, int wid, int tetplac)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if ((sol->x[tetplac] + tet[tetplac].x[i]) < 0 ||
				(sol->x[tetplac] + tet[tetplac].x[i]) > wid - 1)
			return (0);
		if ((sol->y[tetplac] + tet[tetplac].y[i]) < 0 ||
			(sol->y[tetplac] + tet[tetplac].y[i]) > wid - 1)
			return (0);
		i++;
	}
	return (1);
}

static int		ft_testi(t_square *sol, t_tetri *tet, int wid, int tetplac)
{
	int		i;
	int		j;

	if (ft_testsq(sol, tet, wid, tetplac) == 0)
		return (0);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < tetplac * 4)
		{
			if ((sol->x[tetplac] + tet[tetplac].x[i]) == sol->pos[1][j] &&
				(sol->y[tetplac] + tet[tetplac].y[i]) == sol->pos[0][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void		ft_testtet(t_square *sol, t_tetri *tet, int wid, int tetplac)
{
	while (sol->x[tetplac] < wid - 1 || sol->y[tetplac] < wid - 1)
	{
		if (ft_testi(sol, tet, wid, tetplac) == 1)
			return ;
		else
		{
			if (sol->x[tetplac] < wid - 1 && sol->y[tetplac] < wid)
				sol->x[tetplac]++;
			else if (sol->x[tetplac] >= wid - 1 && sol->y[tetplac] < wid - 1)
			{
				sol->x[tetplac] = 0;
				sol->y[tetplac]++;
			}
			else if (sol->x[tetplac] >= wid - 1 && sol->y[tetplac] < wid - 1)
			{
				sol->x[tetplac]++;
				sol->y[tetplac]++;
			}
		}
	}
}

static void		ft_next(t_square *sol, t_tetri *tet, int nbtet)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		sol->pos[0][(sol->tetplaced * 4) + i] =
			sol->y[sol->tetplaced] + tet[sol->tetplaced].y[i];
		sol->pos[1][(sol->tetplaced * 4) + i] =
			sol->x[sol->tetplaced] + tet[sol->tetplaced].x[i];
		i++;
	}
	sol->tetplaced++;
	if (sol->tetplaced != nbtet)
	{
		sol->x[sol->tetplaced] = 0;
		sol->y[sol->tetplaced] = 0;
	}
}

t_square		*ft_solve(int nbtet, t_tetri *tet)
{
	t_square	*sol;

	if ((sol = ft_init(nbtet)) == NULL)
		return (NULL);
	sol->x[0] = 0;
	sol->y[0] = 0;
	while (sol->tetplaced != nbtet)
	{
		ft_testtet(sol, tet, sol->width, sol->tetplaced);
		if (sol->x[sol->tetplaced] >= sol->width - 1 &&
			sol->y[sol->tetplaced] >= sol->width - 1)
			ft_backward(sol);
		else
			ft_next(sol, tet, nbtet);
	}
	return (sol);
}
