/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidzawi <sidzawi@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:17:33 by sidzawi           #+#    #+#             */
/*   Updated: 2024/02/28 22:43:11 by sidzawi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int ac, char **av)
{
	int		i;
	t_utils	u;

	if (ac == 1)
		ft_solve_from_stdin(&u);
	i = 1;
	while (i < ac)
	{
		u.name_file = av[i++];
		ft_solve_from_file(&u);
		ft_clean_utils(&u);
	}
	return (0);
}
