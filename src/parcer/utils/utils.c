/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzahri <hzahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:38:05 by hzahri            #+#    #+#             */
/*   Updated: 2024/03/14 19:37:12 by hzahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

bool	find_c(const char *sep, char c)
{
	while (*sep)
		if (*sep++ == c)
			return (true);
	return (false);
}
char	*ft_strtok(char *str, char *sep)
{
	static char	*hold;
	char		*token;

	if (str)
		hold = str;
	if (!hold || !*hold)
		return (NULL);
	while (*hold && find_c(sep, *hold))
		hold++;
	if (!*hold)
		return (NULL);
	token = hold;
	while (*hold && !find_c(sep, *hold))
		hold++;
	if (*hold)
		*hold++ = 0;
	return (token);
}

int len_n(char n)
{
	int i = -1;
	char *base = "0123456789abcdef";
	if (n >= 'A' && n <= 'F')
		n = n + 32;
	while (base[++i])
	{
		if(base[i] == n)
			return(i);
	}
	return(i);
}

int	ft_atox(char *str)
{
	int res;
	int i;

	i = 0;
	if (str[i] == '0' && str[i+1] == 'x' && str[i+2])
		i = 2;
	else
		ft_error();
	res = 0;
	while (str[i] && i < 10 && ((str[i] <= '9' && str[i] >= '0') || (str[i] <= 'f' && str[i] >= 'a') || (str[i] <= 'F' && str[i] >= 'A')))
		res = res * 16 + len_n(str[i++]);
	// while (str[i] && ((str[i] <= '9' && str[i] >= '0') || (str[i] <= 'f' && str[i] >= 'a') || (str[i] <= 'F' && str[i] >= 'A')))
	// 	res = res * 16 + len_n(str[i++]);
	res = res * 16 + len_n('f');
	res = res * 16 + len_n('f');
	return(res);	
}

int	ft_atoi(char *str)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	if (!str || !*str)
		ft_error();
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	if (!*str)
		ft_error();
	while (*str && *str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - '0');
	if (*str)
		ft_error();
	return (res * sign);
}