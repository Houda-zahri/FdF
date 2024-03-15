/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:23:13 by hzahri            #+#    #+#             */
/*   Updated: 2024/03/15 20:22:18 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	update(t_point *p, t_data *data)
{
	if (!p)
		return ;
	data->distance = (WIDTH <= HEIGHT) * ((HEIGHT / 2) / map_size(0))
		+ (WIDTH > HEIGHT) * ((WIDTH / 2) / line_size(0));
	p->x *= (data->distance + data->zoom);
	p->y *= (data->distance + data->zoom);
	if (p->z > 5)
		p->z += data->axe_z;
	p->x -= ((data->distance + data->zoom) * line_size(0)) / 2;
	p->y -= ((data->distance + data->zoom) * map_size(0)) / 2;
	p_rotation(p, data);
	p->x += data->x_pos + WIDTH / 2;
	p->y += data->y_pos + HEIGHT / 2;
}

t_point	*find_p1(t_point *p, t_line *line)
{
	t_point	*p1;

	p1 = NULL;
	p1 = gcollector(sizeof(t_point), 1);
	p1->x = p->x;
	p1->y = p->y;
	p1->z = line->element[0];
	p1->color = line->element[1];
	return (p1);
}

t_point	*find_p2(t_point *p, t_line *line)
{
	t_point	*p2;

	p2 = NULL;
	if (line->next)
	{
		p2 = gcollector(sizeof(t_point), 1);
		p2->x = p->x + 1;
		p2->y = p->y;
		p2->z = line->next->element[0];
		p2->color = line->next->element[1];
	}
	return (p2);
}

void	find_p3(t_data *data, t_point *p, t_line *line, t_line *tmp)
{
	t_point	*p3;
	t_point	*p1;
	t_point	*p2;

	p3 = NULL;
	if (tmp)
	{
		p3 = gcollector(sizeof(t_point), 1);
		p3->x = p->x;
		p3->y = p->y + 1;
		p3->z = tmp->element[0];
		p3->color = tmp->element[1];
	}
	p1 = find_p1(p, line);
	p2 = find_p2(p, line);
	update(p1, data);
	update(p2, data);
	update(p3, data);
	(p2) && (draw_line(data, *p1, *p2, p2->color), 0);
	(p3) && (draw_line(data, *p1, *p3, p3->color), 0);
}

void	draw_map( t_map *map, t_data *data)
{
	t_point	p;
	t_line	*line;
	t_line	*tmp;

	(1) && (line = NULL, tmp = NULL, p.y = 0, 0);
	while (map)
	{
		line = map->lines;
		(map->next) && (tmp = map->next->lines, 0);
		p.x = 0;
		while (line)
		{
			find_p3(data, &p, line, tmp);
			(tmp) && (tmp = tmp->next, 0);
			(1) && (line = line->next, p.x++, 0);
		}
		(1) && (map = map->next, p.y++);
	}
}
