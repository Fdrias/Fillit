/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reopen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 13:57:17 by apruvost          #+#    #+#             */
/*   Updated: 2017/12/07 22:06:51 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "./libft/libft.h"

int		ft_reopen(int fd, char **str)
{
	if (close(fd) == -1)
	{
		ft_putendl_fd("Error", 2);
		return (-1);
	}
	if ((fd = open(str[1], O_RDONLY)) == -1)
	{
		ft_putendl_fd("Error", 2);
		return (-1);
	}
	return (fd);
}
