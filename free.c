/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 08:39:53 by aamhal            #+#    #+#             */
/*   Updated: 2024/02/18 10:22:16 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array(char **p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free (p);
}

void	free_list(t_list **list)
{
	t_list	*tmp;
	t_list	*tmp1;

	if (*list)
	{
		tmp = (*list);
		while (tmp != NULL)
		{
			tmp1 = tmp->next;
			free(tmp->line);
			free(tmp);
			tmp = tmp1;
		}
		*list = NULL;
	}
}
