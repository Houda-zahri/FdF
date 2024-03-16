/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:06:31 by hzahri            #+#    #+#             */
/*   Updated: 2024/03/15 23:47:10 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	main(int ac, char **av)
{
	t_data	data;

	init_my_data(&data);
	data.mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (my_mlx_err(&data))
		return (gcollector(0, 0), EXIT_FAILURE);
	if (ac == 2)
	{
		data.map = parcer(av[1]);
		isom_rot(&data);
		draw_map(data.map, &data);
		mlx_loop_hook(data.mlx, &my_keyhook, &data);
		mlx_loop(data.mlx);
		mlx_terminate(data.mlx);
		gcollector(0, 0);
	}
}
