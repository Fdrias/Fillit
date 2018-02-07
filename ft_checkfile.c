/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:49:19 by apruvost          #+#    #+#             */
/*   Updated: 2017/12/08 04:23:37 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "./libft/libft.h"

static int	ft_checkalph(char *str)
{
	int		i;
	int		nbdie;
	int		nbdot;
	int		nbback;

	i = 0;
	nbdie = 0;
	nbdot = 0;
	nbback = 0;
	while (i < 20)
	{
		if (str[i] == '#')
			nbdie++;
		else if (str[i] == '.')
			nbdot++;
		else if (str[i] == '\n')
			nbback++;
		i++;
	}
	if (nbdie == 4 && nbdot == 12 && nbback == 4 && str[0] != '\n')
		return (1);
	else
		return (-1);
}

static void	ft_checkconnec(char *str, int *connec, int i)
{
	if (str[i] == '#')
	{
		if (!(i < 5))
		{
			if (str[i - 5] == '#')
				*connec += 1;
		}
		if (!(i > 14))
		{
			if (str[i + 5] == '#')
				*connec += 1;
		}
		if (i != 0 && i != 5 && i != 10 && i != 15
				&& i != 4 && i != 9 && i != 14 && i != 19)
		{
			if (str[i - 1] == '#')
				*connec += 1;
		}
		if (i != 3 && i != 8 && i != 13 && i != 18
				&& i != 4 && i != 9 && i != 14 && i != 19)
		{
			if (str[i + 1] == '#')
				*connec += 1;
		}
	}
}

static int	ft_checktet(char *str)
{
	int		i;
	int		connec;

	i = 0;
	connec = 0;
	if (ft_checkalph(str) == -1)
		return (-1);
	while (i < 20)
	{
		ft_checkconnec(str, &connec, i);
		i++;
	}
	if (connec > 5)
		return (1);
	else
		return (-1);
}

int			ft_checkfile(int fd)
{
	char	*buf;
	int		len;
	int		nbtet;
	int		nbback;

	nbtet = 0;
	nbback = 0;
	if (fd == -1)
		return (-1);
	if ((buf = (char *)malloc(sizeof(char) * 21)) == NULL)
		return (-1);
	while ((len = read(fd, buf, 21)) >= 20)
	{
		if (ft_checktet(buf) == -1)
			nbtet -= 100;
		if (len == 21 && buf[20] != '\n')
			nbtet -= 100;
		else if (len == 21 && buf[20] == '\n')
			nbback++;
		nbtet++;
	}
	ft_strdel(&buf);
	if (nbtet < 0 || nbtet > 26 || len != 0 || nbback != nbtet - 1)
		return (0);
	return (nbtet);
}
