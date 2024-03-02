/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidzawi <sidzawi@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:05:39 by sidzawi           #+#    #+#             */
/*   Updated: 2024/02/28 23:14:13 by sidzawi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_next_line(char *data, int idx)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	while (data[++i] && j < idx)
		if (data[i] == '\n')
			j++;
	if (data[i] == '\n')
		i++;
	j = ft_strlen(&data[i], '\n');
	str = malloc(sizeof(char) * j);
	if (!str)
		return (NULL);
	j = 0;
	while (data[i] && data[i] != '\n')
		str[j++] = data[i++];
	str[j] = '\0';
	return (str);
}

int	ft_split_data(char *data, t_utils *u)
{
	int	len;
	int	i;

	len = 0;
	while (data[len] && data[len] != '\n')
		len++;
	u->matrice = malloc(sizeof(char *) * u->size);
	if (!u->matrice)
		return (0);
	i = -1;
	while (++i < u->size)
	{
		u->matrice[i] = ft_next_line(&data[len + 1], i);
		if (!u->matrice)
		{
			ft_free_mat(u);
			return (0);
		}
	}
	return (1);
}
