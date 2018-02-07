/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 21:28:22 by apruvost          #+#    #+#             */
/*   Updated: 2017/12/19 14:11:46 by fdrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "./libft/libft.h"

t_square	*ft_init(int nbtet)
{
	t_square	*sol;

	if ((sol = (t_square *)malloc(sizeof(t_square))) == NULL)
		return (NULL);
	if ((sol->x = (int *)malloc(sizeof(int) * nbtet)) == NULL)
		return (NULL);
	if ((sol->y = (int *)malloc(sizeof(int) * nbtet)) == NULL)
		return (NULL);
	if ((sol->pos = (int **)malloc(sizeof(int *) * 2)) == NULL)
		return (NULL);
	if ((sol->pos[0] = (int *)malloc(sizeof(int) * (nbtet * 4))) == NULL)
		return (NULL);
	if ((sol->pos[1] = (int *)malloc(sizeof(int) * (nbtet * 4))) == NULL)
		return (NULL);
	sol->tetplaced = 0;
	sol->width = ft_root(nbtet * 4);
	return (sol);
}
