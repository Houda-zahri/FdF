/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 03:35:43 by hzahri            #+#    #+#             */
/*   Updated: 2024/03/16 00:14:37 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	rotation_hook(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		data->rot_x += 0.05;
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		data->rot_x -= 0.05;
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		data->rot_y += 0.05;
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		data->rot_y -= 0.05;
	if (mlx_is_key_down(data->mlx, MLX_KEY_Z))
		data->rot_z += 0.05;
	if (mlx_is_key_down(data->mlx, MLX_KEY_X))
		data->rot_z -= 0.05;
}

void	zoom_hook(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_KP_ADD))
		data->zoom++;
	if (mlx_is_key_down(data->mlx, MLX_KEY_KP_SUBTRACT))
		((data->distance + data->zoom) > 1) && (data->zoom--, 0);
}

void	translation_hook(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->x_pos -= 10;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->x_pos += 10;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		data->y_pos -= 10;
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		data->y_pos += 10;
}

void	my_keyhook(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	rotation_hook(data);
	zoom_hook(data);
	translation_hook(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_F))
		init_my_data(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_I))
	{
		init_my_data(data);
		isom_rot(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_KP_1))
		data->axe_z++;
	if (mlx_is_key_down(data->mlx, MLX_KEY_KP_0))
		data->axe_z--;
	mlx_delete_image(data->mlx, data->image);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	draw_map(data->map, data);
	mlx_image_to_window(data->mlx, data->image, 0, 0);
}
