/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 03:35:43 by hzahri            #+#    #+#             */
/*   Updated: 2024/03/13 23:53:06 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void my_keyhook(void* param)
{
	t_data *data = param;
	// if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
	// 	mlx_close_window(data->mlx);
	// if (mlx_is_key_down(data->mlx, MLX_KEY_KP_ADD))
	// 	data->zoom += 1;
	//--------------------ZOOM-------------------------
	if (mlx_is_key_down(data->mlx, MLX_KEY_KP_ADD ))
		data->zoom++;
	if (mlx_is_key_down(data->mlx, MLX_KEY_KP_SUBTRACT ))
		data->zoom--;
	//--------------------POSITION-------------------------
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT ))
		data->x_pos -= 50;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT ))
		data->x_pos += 50;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN ))
		data->y_pos -= 50;
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP ))
		data->y_pos += 50;
	//--------------------ROTATION-------------------------
	if (mlx_is_key_down(data->mlx, MLX_KEY_D ))
		data->rot_x += 0.5;
	if (mlx_is_key_down(data->mlx, MLX_KEY_A ))
		data->rot_x -= 0.5;
		if (mlx_is_key_down(data->mlx, MLX_KEY_W ))
		data->rot_y += 0.5;
	if (mlx_is_key_down(data->mlx, MLX_KEY_S ))
		data->rot_y -= 0.5;
	//--------------------init-------------------------	
	if (mlx_is_key_down(data->mlx, MLX_KEY_F ))
		init_my_data(data);
	//--------------------rot-------------------------	
	if (mlx_is_key_down(data->mlx, MLX_KEY_I ))
	{
		data->rot_x = 0.523599;
		data->rot_y = -0.523599;
		data->rot_z = 0.523599;
	}
	// if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT ))
	// 	data->x_pos += 100;
	// if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN ))
	// 	data->y_pos -= 100;
	// if (mlx_is_key_down(data->mlx, MLX_KEY_UP ))
	// 	data->y_pos += 100;

	mlx_delete_image(data->mlx, data->image);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx, data->image, 0, 0);
	draw_map(data->map, data);
}