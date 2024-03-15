/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:23:13 by hzahri            #+#    #+#             */
/*   Updated: 2024/03/15 07:09:06 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	update(t_point *p, t_data *data)
{
	if(!p)
		return ;
	data->distance = (WIDTH  <= HEIGHT  ) * ((HEIGHT/2) / map_size(0)) + 
		(WIDTH > HEIGHT) * ((WIDTH/2) / line_size(0)) ;
	p->x *= (data->distance + data->zoom);
	p->y *= (data->distance + data->zoom);

	if (p->z > 5)
		p->z += data->axe_z;

	p->x -= ((data->distance + data->zoom)*line_size(0))/2;
	p->y -= ((data->distance + data->zoom)*map_size(0))/2;
	p_rotation(p, data);
	p->x += data->x_pos;
	p->y += data->y_pos;

    int center_x = WIDTH / 2;
    int center_y = HEIGHT /2 ;

    p->x += center_x;
    p->y += center_y;
}

void draw_map( t_map *map, t_data *data)
{
	int y = 0;
	t_line *line = NULL;
	t_line *tmp = NULL;
	while(map)
	{
		line = map->lines;
		(map->next) && (tmp = map->next->lines, 0);
		int x = 0;
		while(line)
		{
			t_point *p1 = NULL;
			t_point *p2 = NULL;
			t_point *p3 = NULL;
			p1 = gcollector(sizeof(t_point), 1);
			p1->x = x;
			p1->y = y;
			p1->z = line->element[0];
			p1->color = line->element[1];
			if(line->next)
			{
				p2 = gcollector(sizeof(t_point), 1);
				p2->x = x + 1;
				p2->y = y;
				p2->z = line->next->element[0];
				p2->color = line->next->element[1];
			}
			if(tmp)
			{	
				p3 = gcollector(sizeof(t_point), 1);
				p3->x = x;
				p3->y = y + 1;
				p3->z = tmp->element[0];
				p3->color = tmp->element[1];
			}
			update(p1, data);
			update(p2, data);
			update(p3, data);
			(p2) && (draw_line(data, *p1, *p2, p2->color), 0);
			(p3) && (draw_line(data, *p1, *p3, p3->color), 0);
			(tmp) && (tmp = tmp->next, 0);
			line = line->next;
			x++;	
		}
		map = map->next;
		y++;
	}
}
