/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:40:38 by apruvost          #+#    #+#             */
/*   Updated: 2017/12/08 05:37:11 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "./libft/libft.h"

void			ft_del(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

static void		ft_exit(int error, t_tetri *tet, t_square *sol, int fd)
{
	if (tet != NULL)
		ft_del(tet);
	if (sol != NULL)
	{
		if (sol->x != NULL)
			ft_del(sol->x);
		if (sol->y != NULL)
			ft_del(sol->y);
		if (sol->pos != NULL)
		{
			if (sol->pos[0] != NULL)
				ft_del(sol->pos[0]);
			if (sol->pos[1] != NULL)
				ft_del(sol->pos[1]);
			ft_del(sol->pos);
		}
	}
	if (error == 0)
		ft_putendl("Error");
	close(fd);
}

static int		ft_nextmain(int fd, int nbtet, t_tetri *tet, t_square *sol)
{
	if ((tet = ft_gettet(fd, nbtet)) == NULL)
		return (0);
	if ((sol = ft_solve(nbtet, tet)) == NULL)
		return (0);
	if (ft_affsol(sol) == -1)
		return (0);
	return (1);
}

int				main(int argc, char **argv)
{
	int			fd;
	int			nbtet;
	t_tetri		*tet;
	t_square	*sol;

	tet = NULL;
	sol = NULL;
	if ((fd = ft_checkarg(argc, argv)) == -1)
		return (0);
	if ((nbtet = ft_checkfile(fd)) <= 0)
	{
		ft_putendl("error");
		close(fd);
		return (0);
	}
	if ((fd = ft_reopen(fd, argv)) == -1)
		return (0);
	ft_exit(ft_nextmain(fd, nbtet, tet, sol), tet, sol, fd);
	return (0);
}
