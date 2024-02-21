/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:50:32 by aamhal            #+#    #+#             */
/*   Updated: 2024/02/21 09:59:59 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void v()
{
	system("leaks cub3d");
}

int	main(int ac, char **av)
{
	// atexit(v);
	t_list *list;
	t_direct *direct;
	
	if (ac != 2)
		exit(1);
	direct = malloc(sizeof(t_direct));
	parcing(av[1], &list, &direct);
	creat_window(direct);
 
	return (0);
}