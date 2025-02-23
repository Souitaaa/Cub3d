/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_trgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:53:32 by csouita           #+#    #+#             */
/*   Updated: 2025/02/23 18:01:48 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" 

int	create_trgb(int t, int r, int g, int b)
{
	printf("r = %d\n",r);
	printf("g = %d\n",g);
	printf("b = %d\n",b);
	if (r == -1 || g == -1 || b == -1)
		return (-1);
	return (t << 24 | r << 16 | g << 8 | b);
}
