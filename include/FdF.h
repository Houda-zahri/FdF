/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:23:58 by hzahri            #+#    #+#             */
/*   Updated: 2024/03/13 18:17:23 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
#include "MLX42.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#define WIDTH 2000
#define HEIGHT 1400

typedef struct s_gc
{
	void			*content;
	struct s_gc		*next;
}	t_gc;

typedef struct s_line
{
	int	element[2];
	struct s_line	*next;
}	t_line;


typedef struct s_point
{
	int x;
	int y;
	int z;
	int color;
} t_point;

typedef struct s_map
{
	t_line			*lines;
	struct s_map	*next;
}	t_map;

typedef struct s_data
{
	mlx_t *mlx;
	mlx_image_t *image;
	t_map *map ;
	int distance;
	int zoom;
	int x_pos;//+x-x
	int y_pos;//+y-y
	double rot_x;
	double rot_y;
	double rot_z;
} t_data;
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
bool	find_nl(const char *s);
void	*gcollector(size_t size, int mode);
char	*ft_strtok(char *str, char *sep);
int		ft_strcmp(const char *s1, char *s2);
int		valid_file(char *file);
t_line	*parce_line(char *buff);
t_map	*parcer(char *file);
t_line	*create_new(int z);
void	line_push_back(t_line **line, t_line *new);
void	map_push_back(t_map **map, t_map *new);
t_map	*create_map(t_line *lines);
char	**ft_split(char *s);
int		ft_atox(char *str);
int		ft_atoi(char *str);
void	ft_error();
void	draw_line(t_data *data, int x, int y, int x1, int y1, int color);
void	ft_lowline(t_data *data, int x0, int y0, int x1, int y1, int color);
void	draw_map(t_map *map, t_data *data);
void	ft_heightline(t_data *data, int x, int y, int x1, int y1, int color);
int		map_size(char mode);
int		line_size(int mode);
void	p_rotation(t_point *p, t_data *data);
void	init_my_data(t_data *data);
void	my_keyhook( void* param);

#endif