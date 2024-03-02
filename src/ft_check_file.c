/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidzawi <sidzawi@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:25:51 by isadbaib          #+#    #+#             */
/*   Updated: 2024/03/02 22:38:12 by sidzawi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_check_first_line(char *data, t_utils *u)
{
	int	len;

	len = 0;
	while (data[len] && ft_is_printable(data[len]) && data[len] != '\n')
		len++;
	if (len < 4 || (!ft_is_printable(data[len]) && data[len] != '\n'))
		return (0);
	u->plein = data[len - 1];
	u->obstacle = data[len - 2];
	u->vide = data[len - 3];
	u->size = ft_atoi(data, len - 3);
	if (u->size == -1)
		return (0);
	return (1);
}

int	ft_columns(char *data, t_utils *u)
{
	int	i;
	int	col;
	int	line;

	i = 0;
	col = 0;
	line = 0;
	while (data[i])
	{
		if (data[i] == '\n')
		{
			if (line == 1)
				break;
			line++;
			col = 0;
		}
		col++;
		i++;
	}
	u->columns = col;
	return (col);
}

int	ft_check_file_data(char *data, t_utils *u)
{
	if (!ft_check_first_line(data, u) || !ft_columns(data, u))
		return (0);
	return (1);
}
