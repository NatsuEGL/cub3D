/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:58:15 by aamhal            #+#    #+#             */
/*   Updated: 2024/02/18 14:57:17 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parcing(char *av, t_list **l, t_direct **d)
{
	t_list		*list;
	t_direct	*direct;
	char		**dir;
(void)l;
	direct = *d;
	list = NULL;
	if (check_extension(av) == -1)
	{
		printf("error\n");
		exit(1);
	}
	list = fill_list(list, av);
	direct->map = fill_map(&list);
	direct->map = map_resize(direct->map);
	dir = make_dir(&list);
	ft_error(&direct, dir, &list);
	fill_direct(&direct);

}

void	ft_error(t_direct **direct, char **dir, t_list **list)
{
	(void)list;
	if (first_wall((*direct)->map[0]) == -1 || \
	last_wall((*direct)->map) || right_wall((*direct)->map) \
	|| left_wall((*direct)->map) || check_character((*direct)->map) == -1 \
	|| map_iterate((*direct)->map) == -1 \
	|| direction_parc(dir) == -1 || fill_no(&(*direct), dir) == -1 \
	|| fill_so(&(*direct), dir) == -1 \
	|| fill_we(&(*direct), dir) == -1 || fill_ea(&(*direct), dir) == -1 \
	|| fill_c(&(*direct), dir) == -1 || fill_f(&(*direct), dir) == -1)
	{
		printf("wrong map!\n");
		free_array((*direct)->map);
		free_array(dir);
		free_list(&(*list));
		free((*direct));
		exit(1);
	}
}

int	check_extension(char *av)
{
	int		i;
	int		len;
	char	*p;

	i = 3;
	len = ft_strlen(av) -1;
	p = ".cub";
	while (i >= 0)
	{
		if (p[i] != av[len])
		{
			printf("wrong map name\n");
			return (-1);
		}
		i--;
		len--;
	}
	return (0);
}

t_list	*fill_list(t_list *list, char *av)
{
	t_list	*tmp;
	int		fd;

	fd = open(av, O_RDONLY, 0777);
	if (fd <= 0)
	{
		printf("file error\n");
		exit (1);
	}
	while (1)
	{
		char *str = get_next_line(fd);
		if (!str)
			break ;
		tmp = ft_lstnew(str);
		ft_lstadd_back(&list, tmp);
		tmp = tmp->next;
		free(str);
	}
	return (list);
}
