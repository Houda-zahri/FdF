/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:44:39 by hzahri            #+#    #+#             */
/*   Updated: 2024/03/15 23:34:56 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*mal;

	mal = (char *)gcollector(1 + ft_strlen(src), 1);
	if (!mal)
		return (NULL);
	i = -1;
	while (src[++i])
		mal[i] = src[i];
	mal[i] = 0;
	return (mal);
}

int	ft_strcmp(const char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && ((unsigned char)s1[i] == (unsigned char)s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	valid_file(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	while (i && file[i] != '.')
		i--;
	if (!ft_strcmp(file + i, ".fdf"))
		return (open(file, O_RDONLY));
	return (-1);
}

t_line	*parce_line(char *buff)
{
	t_line	*lines;
	t_line	*node;
	char	*token;
	char	**points;
	int		i;

	lines = NULL;
	i = 0;
	points = ft_split(buff);
	while (points[i])
	{
		token = ft_strtok(points[i], ",");
		node = create_new(ft_atoi(token));
		token = ft_strtok(NULL, ",");
		if (token)
			node->element[1] = ft_atox(token);
		line_push_back(&lines, node);
		i++;
	}
	return (lines);
}

t_map	*parcer(char *file)
{
	char	*buffer;
	int		fd;
	t_map	*map;

	map = NULL;
	fd = valid_file(file);
	if (fd == -1)
		return (write(2, "Invalid File \n", 14), ft_error(), NULL);
	buffer = get_next_line(fd);
	if (!buffer)
		return (write(2, "Empty File \n", 12), ft_error(), NULL);
	while (buffer)
	{
		map_push_back(&map, create_map(parce_line(buffer)));
		free(buffer);
		buffer = get_next_line(fd);
	}
	return (map);
}
