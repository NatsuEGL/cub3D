/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:38:06 by aamhal            #+#    #+#             */
/*   Updated: 2024/02/07 10:55:38 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**map_resize(char **map)
{
	int		i;
	size_t	len;

	i = 0;
	len = longest_row(map);
	while (map[i])
	{
		if (ft_strlen(map[i]) < len)
			map[i] = resize_row(map[i], len - ft_strlen(map[i]));
		else
			map[i] = ft_strjoin(map[i], " ");
		i++;
	}
	return (map);
}

int	longest_row(char **map)
{
	int		i;
	size_t	len;

	i = 1;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) > len)
			len = ft_strlen(map[i]);
		i++;
	}
	return (len);
}

char	*resize_row(char *p, int i)
{
	while (i >= 0)
	{
		p = ft_strjoin (p, " ");
		i--;
	}
	return (p);
}
