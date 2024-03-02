/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidzawi <sidzawi@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:57:23 by isadbaib          #+#    #+#             */
/*   Updated: 2024/02/28 22:56:18 by sidzawi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>

# define MAP_ERROR "map error\n"
# define MALLOC_ERROR "malloc error\n"
# define FILE_ERROR "file error\n"
# define SIZE_BUFFER 1000
# define FLAG_READ O_RDONLY

typedef unsigned long long	t_size;

typedef struct s_point
{
	int	x;
	int	y;
	int	max;
}	t_point;

typedef struct s_utils
{
	char	*name_file;
	char	**matrice;
	int		size;
	int		columns;
	char	vide;
	char	plein;
	char	obstacle;
}	t_utils;

int		ft_strlen(char *str, char c);
void	ft_putstr(char *str, int out);
int		ft_get_info_file(t_utils *u);
char	*ft_strdup(char *src);
int		ft_atoi(char *str, int len);
void	ft_error(char *str);
char	*ft_read_file(int fd);
void	ft_solve_from_stdin(t_utils *u);
void	ft_solve_from_file(t_utils *u);
void	ft_clean_utils(t_utils *u);
int		ft_is_printable(char c);
char	*ft_read_stdin(void);
int		ft_check_file_data(char *data, t_utils *u);
int		ft_split_data(char *data, t_utils *u);
void	ft_solve(t_utils *u);
void	ft_free_mat(t_utils *u);

#endif