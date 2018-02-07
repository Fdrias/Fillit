/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:04:35 by apruvost          #+#    #+#             */
/*   Updated: 2017/12/08 05:28:07 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <fcntl.h>

int		ft_checkarg(int nbarg, char **str)
{
	int	fd;

	if (nbarg != 2)
	{
		ft_putendl("usage: test source_file");
		ft_putendl("          there must be only one file");
		return (-1);
	}
	if ((fd = open(str[1], O_RDONLY)) == -1)
	{
		ft_putendl("Can't open file, check if valid and perms");
		return (-1);
	}
	return (fd);
}
