/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:44:47 by apruvost          #+#    #+#             */
/*   Updated: 2017/12/19 18:59:53 by fdrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

typedef struct		s_tetri
{
	int				x[4];
	int				y[4];
}					t_tetri;
typedef struct		s_square
{
	int				*x;
	int				*y;
	int				tetplaced;
	int				width;
	int				**pos;
}					t_square;

int					ft_checkfile(int fd);
int					ft_checkarg(int argc, char **argv);
int					ft_reopen(int fd, char **str);
t_tetri				*ft_gettet(int fd, int nbtet);
t_square			*ft_solve(int nbtet, t_tetri *tet);
int					ft_affsol(t_square *sol);
int					ft_root(int nb);
void				ft_del(void *ptr);
t_square			*ft_init(int nbtet);
void				ft_backward(t_square *sol);
#endif
