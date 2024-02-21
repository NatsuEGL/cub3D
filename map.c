/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:42:51 by aamhal            #+#    #+#             */
/*   Updated: 2024/02/18 14:57:47 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list	*find_map(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (!find_line(tmp->line))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

char	**fill_map(t_list **list)
{
	t_list	*tmp;
	char	*p;
	char	**map;

	tmp = find_map(list);
	p = ft_strdup("");
	if (tmp == NULL)
	{
		printf("map not found\n");
		exit(1);
	}
	while (tmp)
	{
		p = ft_strjoin(p, tmp->line);
		tmp = tmp->next;
		if (tmp && !tmp->line)
			break ;
	}
	map = ft_split(p, '\n');
	free(p);
	return (map);
}

int	find_line(char *p)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (p[i])
	{
		if (!ft_isdigit(p[i]) && p[i] != ' ' && p[i] != '	' && p[i] != '\n')
			return (-1);
		else if (ft_isdigit(p[i]))
			count++;
		i++;
	}
	if (count == 0)
		return (-1);
	return (0);
}
