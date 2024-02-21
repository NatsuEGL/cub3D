/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:41:38 by aamhal            #+#    #+#             */
/*   Updated: 2024/02/18 10:43:07 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_character(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map_iterate_norm(map[i][j], &count) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	if (count != 1)
		return (-1);
	return (0);
}

int	map_iterate_norm(char c, int *count)
{
	int i;

	i = *count;
	if (c != '1' && c != ' ' && c != '0' && \
	c != 'N' && c != 'S' && c != 'E' \
	&& c != 'W' && c != '\n')
		return (-1);
	if (c == 'N')
		i++;
	if (c == 'E')
		i++;
	if (c == 'S')
		i++;
	if (c == 'W')
		i++;
	*count = i;
	return (0);
}

int	map_iterate(char **map)
{

	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'W' \
					|| map[i][j] == 'E' || map[i][j] == 'S')
			{
				if (if_map_cover(map, i, j) == -1)
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	if_map_cover(char **map, int i, int j)
{
	if (map[i + 1][j] && map[i + 1][j] == ' ')
		return (-1);
	if (map[i - 1][j] && map[i - 1][j] == ' ')
		return (-1);
	if (map[i][j + 1] && map[i][j + 1] == ' ')
		return (-1);
	if (map[i][j - 1] && map[i][j - 1] == ' ')
		return (-1);
	return (0);
}
