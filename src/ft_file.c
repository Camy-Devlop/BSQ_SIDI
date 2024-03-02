/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidzawi <sidzawi@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:25:51 by isadbaib          #+#    #+#             */
/*   Updated: 2024/02/28 23:05:12 by sidzawi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_join(char *res, char *buff)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(sizeof(char) * (ft_strlen(res, '\0') + \
		ft_strlen(buff, '\0') + 1));
	if (!str)
		return (str);
	i = 0;
	j = 0;
	while (res && res[j])
		str[i++] = res[j++];
	j = 0;
	while (buff && buff[j])
		str[i++] = buff[j++];
	str[i] = '\0';
	if (res)
		free(res);
	return (str);
}

void	*ft_free_chars(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return ((void *) NULL);
}

char	*ft_read_file(int fd)
{
	int		d;
	char	*buff;
	char	*res;

	d = 1;
	buff = malloc(sizeof(char) * SIZE_BUFFER + 1);
	if (!buff)
		return (NULL);
	res = NULL;
	while (d)
	{
		d = read(fd, buff, SIZE_BUFFER);
		if (d < 0)
			return (ft_free_chars(buff, res));
		if (d == 0)
			break ;
		buff[d] = '\0';
		res = ft_join(res, buff);
		if (!res)
			return (NULL);
	}
	free(buff);
	return (res);
}

char	*ft_read_stdin(void)
{
	int		d;
	char	*buff;
	char	*res;

	d = 1;
	buff = malloc(sizeof(char) * 2);
	if (!buff)
		return (NULL);
	res = NULL;
	while (d)
	{
		d = read(STDIN_FILENO, buff, 1);
		if (d < 0)
			return (ft_free_chars(buff, res));
		if (d == 0)
			break ;
		buff[d] = '\0';
		res = ft_join(res, buff);
		if (!res)
			return (NULL);
	}
	return (res);
}
