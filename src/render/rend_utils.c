/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:11:38 by hzahri            #+#    #+#             */
/*   Updated: 2024/03/15 21:19:23 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	init_my_data(t_data *data)
{
	data->distance = 0;
	data->rot_x = 0;
	data->rot_y = 0;
	data->rot_z = 0;
	data->zoom = 0;
	data->x_pos = 0;
	data->y_pos = 0;
	data->axe_z = 0;
}

void	isom_rot(t_data *data)
{
	data->rot_x = 0.523599;
	data->rot_y = -0.523599;
	data->rot_z = 0.523599;
}

int	my_mlx_err(t_data *data)
{
	if (!(data->mlx))
	{
		puts(mlx_strerror(mlx_errno));
		return (1);
	}
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!(data->image))
	{
		mlx_close_window(data->mlx);
		puts(mlx_strerror(mlx_errno));
		return (1);
	}
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1)
	{
		mlx_close_window(data->mlx);
		puts(mlx_strerror(mlx_errno));
		return (1);
	}
	return (0);
}
// int get_r(int rgba)
// {
//     // Move 3 bytes to the right and mask out the first byte.
//     return ((rgba >> 24) & 0xFF);
// }

// // Get the green channel.
// int get_g(int rgba)
// {
//     // Move 2 bytes to the right and mask out the first byte.
//     return ((rgba >> 16) & 0xFF);
// }

// // Get the blue channel.
// int get_b(int rgba)
// {
//     // Move 1 byte to the right and mask out the first byte.
//     return ((rgba >> 8) & 0xFF);
// }

// // Get the alpha channel.
// int get_a(int rgba)
// {
//     // Move 0 bytes to the right and mask out the first byte.
//     return (rgba & 0xFF);
// }

// // 'Encodes' four individual bytes into an int.
// int get_rgba(int rgba)
//	return (get_r(rgba) << 24 | get_g(rgba) << 16 
// | get_b(rgba) << 8 | get_a(rgba));