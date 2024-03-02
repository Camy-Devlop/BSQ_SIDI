/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidzawi <sidzawi@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:24:33 by sidzawi           #+#    #+#             */
/*   Updated: 2024/02/28 23:04:14 by sidzawi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

void	ft_free_mat(t_utils *u)
{
	int	i;

	i = 0;
	while (i < u->size)
		if (u->matrice && u->matrice[i])
			free(u->matrice[i++]);
	if (u->matrice)
		free(u->matrice);
}

void	ft_clean_utils(t_utils *u)
{
	u->name_file = "";
	u->size = 0;
	u->columns = 0;
	u->vide = 0;
	u->plein = 0;
	u->obstacle = 0;
	ft_free_mat(u);
}
