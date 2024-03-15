/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:06:34 by hzahri            #+#    #+#             */
/*   Updated: 2024/03/15 08:21:36 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_line	*create_new(int z)
{
	t_line	*node;

	node = gcollector(sizeof(t_line), 1);
	node->element[0] = z;
	node->element[1] = 0xffffffff;
	node->next = NULL;
	return (node);
}

int	line_size(int mode )
{
	static int	size;

	if (mode)
		return (size = mode, 0);
	return (size);
}

void	line_push_back(t_line **line, t_line *new)
{
	t_line	*head;

	if (!line || !new)
		return ;
	if (*line)
	{
		head = *line;
		while (head->next)
			head = head->next;
		head->next = new ;
	}
	else
		*line = new;
}

static int	count_str(char const *s)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (s[++i])
	{
		if (s[i] != ' ' && ((i && s[i - 1] == ' ') || i == 0))
			len++;
	}
	return (len);
}

char	**ft_split(char *s)
{
	int		j;
	char	**ptr;
	char	*token;
	int		count;

	count = count_str(s);
	if (!line_size(0))
		line_size(count);
	if (!s || count != line_size(0))
		ft_error();
	ptr = gcollector((count + 1) * sizeof(char *), 1);
	if (ptr == NULL)
		return (NULL);
	j = 0;
	token = ft_strtok(s, " ");
	while (token)
	{
		ptr[j++] = ft_strdup(token);
		token = ft_strtok(NULL, " ");
	}
	ptr[j] = token;
	return (ptr);
}
