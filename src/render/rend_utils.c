/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:11:38 by hzahri            #+#    #+#             */
/*   Updated: 2024/03/13 18:00:35 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void init_my_data(t_data *data)
{
	data->distance = 0;
	data->rot_x = 0;
	data->rot_y = 0;
	data->rot_z = 0;
	data->zoom = 0;
	data->x_pos = 0;
	data->y_pos = 0;
}