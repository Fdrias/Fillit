/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backward.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 01:30:38 by apruvost          #+#    #+#             */
/*   Updated: 2017/12/08 02:40:14 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_backward(t_square *sol)
{
	if (sol->tetplaced != 0)
	{
		sol->tetplaced--;
		sol->x[sol->tetplaced]++;
	}
	else
	{
		sol->width++;
		sol->x[0] = 0;
		sol->y[0] = 0;
	}
}
