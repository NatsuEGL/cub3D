/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:02:51 by aamhal            #+#    #+#             */
/*   Updated: 2024/02/18 11:00:58 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void fill_direct(t_direct **direct)
{
	int	i;
	int	j;

	i = 0;
	while((*direct)->map[i])
	{
		j = 0;
		while((*direct)->map[i][j])
		{
			if ((*direct)->map[i][j] == 'N' || (*direct)->map[i][j] == 'W' || (*direct)->map[i][j] == 'S' || (*direct)->map[i][j] == 'E')
			{
				(*direct)->p_x = j + 1;
				(*direct)->p_y = i + 1;
			}
			j++;
		}
		i++;
	}
	(*direct)->Width = j;
	(*direct)->height = i;
}