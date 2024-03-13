/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map->c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:54:04 by hzahri            #+#    #+#             */
/*   Updated: 2024/03/12 07:01:45 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <math.h>

void update(t_point *p, t_data *data)
{
	if(!p)
		return ;
	data->distance = (WIDTH  <= HEIGHT  ) * ((HEIGHT/2) / map_size(0)) + 
		(WIDTH > HEIGHT) * ((WIDTH/2) / line_size(0));
	// (data->distance < 5) && (data->distance = 5, 0);
	p->x *= (data->distance + data->zoom);
	p->y *= (data->distance + data->zoom);

	p_rotation(p, data);
	p->x += data->x_pos;
	p->y += data->y_pos;

    int center_x = WIDTH / 2;
    int center_y = HEIGHT /2 - (HEIGHT/4);

    // Apply offset to center the parallelogram
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
			if(p2)
				//drawline between p & p2
				draw_line(data, p1->x, p1->y, p2->x, p2->y, p2->color);
			if(p3)
				//drawline btwn p & p3
				draw_line(data, p1->x, p1->y, p3->x, p3->y, p3->color);
			if(tmp)
				tmp = tmp->next;
			line = line->next;
			x++;	
		}
		map = map->next;
		y++;
	}
}
