/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:49:40 by hzahri            #+#    #+#             */
/*   Updated: 2024/03/15 23:34:02 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup_gnl(s2));
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (free((void *)s1), NULL);
	(1) && (i = 0, j = 0);
	while (s1[j])
		ptr[i++] = s1[j++];
	j = 0;
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (free((void *)s1), ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

char	*ft_strdup_gnl(const char *src)
{
	int		i;
	char	*mal;

	mal = (char *)malloc(1 + ft_strlen(src));
	if (!mal)
		return (NULL);
	i = -1;
	while (src[++i])
		mal[i] = src[i];
	mal[i] = 0;
	return (mal);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*ptr;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup_gnl(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = -1;
	while (s[start + (++i)] && i < len)
		ptr[i] = s[start + i];
	ptr[i] = 0;
	return (ptr);
}

bool	find_nl(const char *s)
{
	while (*s)
		if (*s++ == '\n')
			return (true);
	return (false);
}
