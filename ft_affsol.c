/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affsol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 12:15:29 by apruvost          #+#    #+#             */
/*   Updated: 2017/12/08 02:43:52 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "./libft/libft.h"

static char		**square_create(t_square *sol)
{
	char	**str;
	int		i;

	i = 0;
	if ((str = (char **)malloc(sizeof(char *) * sol->width)) == NULL)
		return (NULL);
	while (i < sol->width)
	{
		if ((str[i] = (char *)malloc(sizeof(char) * sol->width + 1)) == NULL)
		{
			i--;
			while (i > -1)
			{
				ft_del(str[i]);
				i--;
			}
			ft_del(str);
			return (NULL);
		}
		i++;
	}
	return (str);
}

void			init_square(char **str, int width)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < width)
	{
		x = 0;
		while (x < width)
		{
			str[y][x] = '.';
			x++;
		}
		str[y][x] = '\0';
		y++;
	}
}

void			ft_affstr(char **square, int width)
{
	int		i;

	i = 0;
	while (i < width)
	{
		ft_putendl(square[i]);
		i++;
	}
}

void			ft_freesquare(char **str, int width)
{
	int		i;

	i = 0;
	while (i < width)
	{
		ft_del(str[i]);
		i++;
	}
	ft_del(str);
}

int				ft_affsol(t_square *sol)
{
	char	**square;
	int		x;
	int		y;

	if ((square = square_create(sol)) == NULL)
		return (-1);
	x = 0;
	y = 0;
	init_square(square, sol->width);
	while (x < sol->tetplaced * 4 && y < sol->tetplaced * 4)
	{
		square[sol->pos[0][y]][sol->pos[1][x]] = (x / 4) + 'A';
		x++;
		y++;
	}
	ft_affstr(square, sol->width);
	ft_freesquare(square, sol->width);
	return (0);
}
