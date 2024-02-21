/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:54:54 by aamhal            #+#    #+#             */
/*   Updated: 2024/02/07 09:32:18 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	fill_c(t_direct **direct, char **dir)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (dir[i])
	{
		j = 0;
		k = 0;
		while (dir[i][j] == ' ')
			j++;
		if (dir[i][j] == 'C')
		{
			while (dir[i][j] && "C "[k] && dir[i][j] == "C "[k])
			{
				j++;
				k++;
			}
			if (!"C "[k])
				return ((*direct)->c = ft_strdup(dir[i]), 0);
		}
		i++;
	}
	return (-1);
}

int	fill_f(t_direct **direct, char **dir)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (dir[i])
	{
		j = 0;
		k = 0;
		while (dir[i][j] == ' ')
			j++;
		if (dir[i][j] == 'F')
		{
			while (dir[i][j] && "F "[k] && dir[i][j] == "F "[k])
			{
				j++;
				k++;
			}
			if (!"F "[k])
				return ((*direct)->f = ft_strdup(dir[i]), 0);
		}
		i++;
	}
	return (-1);
}
