/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gcollector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:12:19 by hzahri            #+#    #+#             */
/*   Updated: 2024/03/15 08:19:50 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	clear_gc(t_gc **gc)
{
	t_gc	*tmp;
	t_gc	*node;

	tmp = *gc;
	while (tmp)
	{
		node = tmp;
		tmp = tmp->next;
		free(node->content);
		free(node);
	}
	gc = NULL;
}

void	*gcollector(size_t size, int mode)
{
	static t_gc	*gc;
	t_gc		*node;
	void		*data;

	if (mode)
	{
		data = malloc(size);
		if (!data)
			return (clear_gc(&gc), NULL);
		node = malloc(sizeof(t_gc));
		if (!node)
			return (clear_gc(&gc), free(data), NULL);
		node->content = data;
		node->next = gc;
		gc = node;
		return (data);
	}
	else
		return (clear_gc(&gc), NULL);
}

void	ft_error(void)
{
	gcollector(0, 0);
	write(2, "Error\n", 6);
	exit(1);
}
