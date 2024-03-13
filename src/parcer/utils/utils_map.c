/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:39:19 by hzahri            #+#    #+#             */
/*   Updated: 2024/03/09 04:03:55 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_map	*create_map(t_line *lines)
{
	t_map	*node;

	node = gcollector(sizeof(t_map), 1);
	node->lines = lines;
	node->next = NULL;
	return (node);
}

int	map_size(char mode)
{
	static int	size;

	if (mode == 1)
		return (size++, 0);
	return (size);
}

t_map	*ft_maplast(t_map *map)
{
	t_map	*m;

	m = map;
	if (!map)
		return (NULL);
	if (m == NULL)
		return (NULL);
	while (m->next != NULL)
	{
		m = m->next;
	}
	return (m);
}

void	map_push_back(t_map **map, t_map *new)
{
	if (!map || !new)
		return ;
	if (*map != NULL)
		ft_maplast(*map)->next = new;
	else 
		*map = new; 
	map_size(1);
}