/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:10:46 by hzahri            #+#    #+#             */
/*   Updated: 2024/03/14 21:50:31 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <math.h>

void p_rotation(t_point *p, t_data *data)
{
	
	t_point	*p1 = gcollector(sizeof(t_point), 1);
	
	*p1 = *p;
	p1->x = p->x;
	p1->y = p->y * cos(data->rot_x) - (p->z * sin(data->rot_x));
	p1->z = p->y * sin(data->rot_x) + p->z * cos(data->rot_x);
	*p = *p1;
	p->x = p1->x * cos((data->rot_y)) + p1->z * sin((data->rot_y));
	p->y = p1->y;
	p->z = p1->x * -sin(data->rot_y) + p1->z * cos(data->rot_y);
	*p1 = *p;
	p1->x = p->x * cos(data->rot_z) + p->y * -sin(data->rot_z);
	p1->y = p->x * sin(data->rot_z) + p->y * cos(data->rot_z);
	p1->z = p->z;
	*p = *p1;
}