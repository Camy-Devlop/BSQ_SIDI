/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_and_solve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidzawi <sidzawi@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:06:28 by sidzawi           #+#    #+#             */
/*   Updated: 2024/02/28 23:00:47 by sidzawi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_solve_from_stdin(t_utils *u)
{
	char	*file_data;

	file_data = ft_read_stdin();
	if (!file_data)
		return (ft_error(MAP_ERROR));
	if (!ft_check_file_data(file_data, u))
	{
		free(file_data);
		return (ft_error(MAP_ERROR));
	}
	if (!ft_split_data(file_data, u))
		return (ft_error(MALLOC_ERROR));
	ft_solve(u);
}

void	ft_solve_from_file(t_utils *u)
{
	char	*file_data;
	int		fd;

	fd = open(u->name_file, FLAG_READ);
	if (fd < 0)
		return (ft_error(FILE_ERROR));
	file_data = ft_read_file(fd);
	close(fd);
	if (!file_data)
		return (ft_error(MAP_ERROR));
	if (!ft_check_file_data(file_data, u))
	{
		free(file_data);
		return (ft_error(MAP_ERROR));
	}
	if (!ft_split_data(file_data, u))
		return (ft_error(MALLOC_ERROR));
	ft_solve(u);
}
