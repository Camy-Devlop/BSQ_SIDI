/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidzawi <sidzawi@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:13:59 by sidzawi           #+#    #+#             */
/*   Updated: 2024/02/28 23:16:41 by sidzawi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_print_mat(t_utils *u)
{
	int	i;

	i = 0;
	while (i < u->size)
	{
		ft_putstr(u->matrice[i++], 1);
		ft_putstr("\n", 1);
	}
}

int	ft_can_go_next(t_utils *u, int i, int j, int k)
{
	int	a;

	if (u->matrice[i + k][j + k] != u->vide)
		return (0);
	a = i;
	while (a < u->size && a < i + k)
		if (u->matrice[a++][j + k] == u->obstacle)
			return (0);
	a = j;
	while (a < u->columns && a < j + k)
		if (u->matrice[i + k][a++] == u->obstacle)
			return (0);
	return (1);
}

void	ft_fill_mat(t_utils *u, t_point p)
{
	int	i;
	int	j;

	if (!p.max)
		return (ft_error(MAP_ERROR));
	i = p.y;
	while (i < u->size && i < p.y + p.max)
	{
		j = p.x;
		while (j < u->columns && j < p.x + p.max)
			u->matrice[i][j++] = u->plein;
		i++;
	}
	ft_print_mat(u);
}

void	ft_solve(t_utils *u)
{
	t_point	point;
	int		i;
	int		j;
	int		k;

	i = -1;
	point.max = 0;
	while (++i < u->size)
	{
		j = -1;
		while (++j < u->columns)
		{
			k = 0;
			while (i + k < u->size && j + k < u->columns && 
				ft_can_go_next(u, i, j, k))
				k++;
			if (k > point.max)
			{
				point.y = i;
				point.x = j;
				point.max = k;
			}
		}
	}
	ft_fill_mat(u, point);
}
