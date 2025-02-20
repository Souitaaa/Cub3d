/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:54:07 by csouita           #+#    #+#             */
/*   Updated: 2025/02/20 19:19:18 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

long	ft_atoi(char *str)
{
	long (i), (sig), (res);
	res = 0;
	i = 0;
	sig = 1;
	while (str[i] == 32 && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig = -1;
		i++;
	}
	// if ((ft_strlen(&str[i]) > 3))
	// 	return (-2147483649);
	while (str[i] >= '0' && str[i] <= '9' && str[i])
		res = res * 10 + str[i++] - '0';
	if (res * sig > 255 || res * sig < 0)
		return (-2147483649);
	return (sig * res);
}
