/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhal <aamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:25:30 by aamhal            #+#    #+#             */
/*   Updated: 2024/02/18 14:55:24 by aamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list	*ft_lstnew(char *p)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (0);
	head->line = ft_strdup(p);
	head->next = NULL;
	return (head);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	head = *lst;
	if (head)
	{
		while (head->next)
			head = head->next;
		head->next = new;
	}
	else
		*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*p;

	count = 0;
	if (lst == NULL)
		return (0);
	p = lst;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return (count);
}

void	print_nodes2(t_list *s)
{
	t_list	*current;

	current = s;
	while (current != NULL)
	{
		printf("%s", current->line);
		current = current->next;
	}
}
