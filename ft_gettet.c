/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:16:00 by apruvost          #+#    #+#             */
/*   Updated: 2017/12/07 22:37:04 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "./libft/libft.h"

static void	ft_rectet(t_tetri *tet, char *buf)
{
	int		i;
	int		block;
	int		origin;

	i = 0;
	block = 0;
	origin = -1;
	while (i < 19)
	{
		if (buf[i] == '#' && origin == -1)
		{
			origin = i;
			tet->x[block] = 0;
			tet->y[block] = 0;
			block++;
		}
		else if (buf[i] == '#' && origin != -1 && block < 4)
		{
			tet->x[block] = (i % 5) - (origin % 5);
			tet->y[block] = (i / 5) - (origin / 5);
			block++;
		}
		i++;
	}
}

t_tetri		*ft_gettet(int fd, int nbtet)
{
	t_tetri		*tet;
	char		*buf;
	int			i;

	if ((tet = (t_tetri *)malloc(sizeof(t_tetri) * nbtet)) == NULL)
		return (NULL);
	if ((buf = (char *)malloc(sizeof(char) * 21)) == NULL)
	{
		free(tet);
		tet = NULL;
		return (NULL);
	}
	i = 0;
	while (read(fd, buf, 21))
	{
		ft_rectet(&tet[i], buf);
		i++;
	}
	ft_strdel(&buf);
	return (tet);
}
