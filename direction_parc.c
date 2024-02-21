/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_parc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:21:12 by aamhal            #+#    #+#             */
/*   Updated: 2024/02/18 10:43:22 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	direction_parc(char **dir)
{
	int	count;

	count = counting_dir(dir);
	if (count != 6)
		return (-1);
	return (0);
}

char	**make_dir(t_list **list)
{
	t_list	*tmp;
	t_list	*l;
	char	**dir;
	char	*p;

	tmp = *list;
	l = find_map(list);
	dir = NULL;
	p = ft_strdup("");
	while (tmp != l)
	{
		p = ft_strjoin(p, tmp->line);
		tmp = tmp->next;
	}
	dir = ft_split(p, '\n');
	free(p);
	return (dir);
}

int	counting_dir(char **dir)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (dir[i])
	{
		if (check_is_empty(dir[i]) == -1)
			count++;
		i++;
	}
	return (count);
}

int	check_is_empty(char *p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		if (p[i] != ' ' && p[i] != '\n')
			return (-1);
		i++;
	}
	return (0);
}
