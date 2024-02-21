/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:32:25 by aamhal            #+#    #+#             */
/*   Updated: 2024/02/07 08:53:25 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	left_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && (map[i][j] == ' '))
			j++;
		if (map[i][j] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	right_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = ft_strlen(map[i]) - 1;
		while (map[i][j] == ' ' || map[i][j] == '	')
			j--;
		if (map[i][j] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	first_wall(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '1' && map[i] != ' ' && map[i] != '\n' )
			return (-1);
		i++;
	}
	return (0);
}

int	last_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
		j++;
	j--;
	while (map[j][i])
	{
		if (map[j][i] != '1' && map[j][i] != ' ' && map[j][i] != '\n')
			return (-1);
		i++;
	}
	return (0);
}
