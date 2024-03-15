/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:40:39 by hzahri            #+#    #+#             */
/*   Updated: 2024/03/15 21:13:12 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	ft_lowline(t_data *data, t_point p0, t_point p1, int color)
{
	int	d;
	int	inc;
	int	dy;
	int	dx;

	inc = 1;
	dy = p1.y - p0.y;
	dx = p1.x - p0.x;
	(dy < 0) && (inc = -1, dy = -dy, 0);
	d = 2 * (dy - dx);
	while (p0.x <= p1.x)
	{
		if (d > 0)
		{
			p0.y = p0.y + inc;
			d = d + (2 * (dy - dx));
		}
		else
			d = d + (2 * dy);
		if ((p0.x >= 0 && p0.y >= 0) && (p0.x < WIDTH && p0.y < HEIGHT))
			mlx_put_pixel(data->image, p0.x, p0.y, color);
		p0.x++;
	}
}

void	ft_heightline(t_data *data, t_point p0, t_point p1, int color)
{
	int	d;
	int	inc;
	int	dy;
	int	dx;

	inc = 1;
	dy = p1.y - p0.y;
	dx = p1.x - p0.x;
	(dx < 0) && (inc = -1, dx = -dx, 0);
	d = 2 * (dx - dy);
	while (p0.y <= p1.y)
	{
		if (d > 0)
		{
			p0.x = p0.x + inc;
			d = d + (2 * (dx - dy));
		}
		else
			d = d + (2 * dx);
		if ((p0.x >= 0 && p0.y >= 0) && (p0.x < WIDTH && p0.y < HEIGHT))
			mlx_put_pixel(data->image, p0.x, p0.y, color);
		p0.y++;
	}
}

void	draw_line(t_data *data, t_point p0, t_point p1, int color)
{
	if (abs(p1.y - p0.y) < abs(p1.x - p0.x))
	{
		if (p0.x > p1.x)
			ft_lowline(data, p1, p0, color);
		else
			ft_lowline(data, p0, p1, color);
	}
	else
	{
		if (p0.y > p1.y)
			ft_heightline(data, p1, p0, color);
		else
			ft_heightline(data, p0, p1, color);
	}
}
