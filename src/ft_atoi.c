/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidzawi <sidzawi@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:10:14 by isadbaib          #+#    #+#             */
/*   Updated: 2024/02/28 22:56:55 by sidzawi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_atoi(char *str, int len)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9' && i < len)
	{
		nb = (nb * 10) + str[i] - '0';
		i++;
	}
	if (i == 0)
		return (-1);
	return (nb);
}
