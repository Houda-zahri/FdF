/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:40:39 by hzahri            #+#    #+#             */
/*   Updated: 2024/03/12 23:46:22 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void ft_lowline(t_data *data, int x, int y, int x1, int y1, int color)
{
	(void)color;
	int d;
	int inc = 1;
	int dy = y1 - y;
	int dx = x1 - x;
	if (dy < 0)
	{
		inc = -1;
		dy = -dy;
	}
	d = 2 * (dy - dx);
	while (x <= x1)
	{
		if (d > 0)
		{
			y = y + inc;
			d = d + (2 * (dy - dx));
		}
		else
			d = d + (2 * dy);
		if ((x >= 0 && y >= 0)&& (x < WIDTH && y < HEIGHT))
			mlx_put_pixel(data->image, x, y, color);
		x++;
	}
}
void ft_heightline(t_data *data, int x, int y, int x1, int y1, int color)
{
	(void)color;
	int d;
	int inc = 1;
	int dy = y1 - y;
	int dx = x1 - x;
	if (dx < 0)
	{
		inc = -1;
		dx = -dx;
	}
	d = 2 * (dx - dy);
	while (y <= y1)
	{
		if (d > 0)
		{
			x = x + inc;
			d = d + (2 * (dx - dy));
		}
		else
			d = d + (2 * dx);
		if ((x >= 0 && y >= 0)&& (x < WIDTH && y < HEIGHT))
			mlx_put_pixel(data->image, x, y, color);
		y++;
	}
}

void draw_line(t_data *data, int x, int y, int x1, int y1, int color)
{
	if (abs(y1 - y) < abs(x1 - x))
	{
		if (x > x1)
			ft_lowline(data, x1, y1, x, y, color);
		else
			ft_lowline(data, x, y, x1, y1, color);
	}
	else
	{
		if (y > y1)
			ft_heightline(data, x1, y1, x, y, color);
		else
			ft_heightline(data, x, y, x1, y1, color);
	}
}
