/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:32:49 by aamhal            #+#    #+#             */
/*   Updated: 2024/02/18 10:50:21 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	fill_no(t_direct **direct, char **dir)
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
		if (dir[i][j] == 'N')
		{
			while (dir[i][j] && "NO "[k] && dir[i][j] == "NO "[k])
			{
				j++;
				k++;
			}
			if (!"NO "[k])
				return ((*direct)->north = ft_strdup(dir[i]), 0);
		}
		i++;
	}
	return (-1);
}

int	fill_so(t_direct **direct, char **dir)
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
		if (dir[i][j] == 'S')
		{
			while (dir[i][j] && "SO "[k] && dir[i][j] == "SO "[k])
			{
				j++;
				k++;
			}
			if (!"SO "[k])
				return ((*direct)->south = ft_strdup(dir[i]), 0);
		}
		i++;
	}
	return (-1);
}

int	fill_we(t_direct **direct, char **dir)
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
		if (dir[i][j] == 'W')
		{
			while (dir[i][j] && "WE "[k] && dir[i][j] == "WE "[k])
			{
				j++;
				k++;
			}
			if (!"WE "[k])
				return ((*direct)->west = ft_strdup(dir[i]), 0);
		}
		i++;
	}
	return (-1);
}

int	fill_ea(t_direct **direct, char **dir)
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
		if (dir[i][j] == 'E')
		{
			while (dir[i][j] && "EA "[k] && dir[i][j] == "EA "[k])
			{
				j++;
				k++;
			}
			if (!"EA "[k])
				return ((*direct)->east = ft_strdup(dir[i]), 0);
		}
		i++;
	}
	return (-1);
}
