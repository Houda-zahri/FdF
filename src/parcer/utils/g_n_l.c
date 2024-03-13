/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_n_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:44:44 by hzahri            #+#    #+#             */
/*   Updated: 2024/03/01 23:09:41 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

char	*feedthefish(int fd, char *fish)
{
	char	*buffer;
	ssize_t	ret;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (free(fish), buffer);
	(1) && (ret = 1, *buffer = 0);
	while (ret && !find_nl(buffer))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
			return (free(fish), free(buffer), NULL);
		buffer[ret] = 0;
		fish = ft_strjoin(fish, buffer);
		if (!fish || !*fish)
			return (free(fish), free(buffer), NULL);
	}
	return (free(buffer), fish);
}

char	*slice_the_fish(char **fish)
{
	int		len;
	char	*line;
	char	*save;

	len = 0;
	save = *fish;
	while (save[len] && save[len] != '\n')
		len++;
	line = ft_substr(*fish, 0, len);
	(save[len] == '\n') && (len++);
	*fish = ft_substr(save, len, ft_strlen(save + len));
	return (free(save), line);
}

char	*get_next_line(int fd)
{
	static char	*fish;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fish = feedthefish(fd, fish);
	if (!fish)
		return (fish);
	line = slice_the_fish(&fish);
	if (!line)
		return (free(fish), fish = NULL, NULL);
	return (line);
}
