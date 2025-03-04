/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_trgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:53:32 by csouita           #+#    #+#             */
/*   Updated: 2025/03/04 01:00:35 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	if (r == -1 || g == -1 || b == -1)
		return (-1);
	return (t << 24 | r << 16 | g << 8 | b);
}

int	handle_colors(char *line)
{
	int		i;
	int		count;
	char	**split;
	int		color;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		ft_error("Error\nInvalid color\n");
	split = ft_split(line, ',');
	if (count_split(split) != 3)
		ft_error("Error\nInvalid color\n");
	color = create_trgb(1, ft_atoi(split[0]), ft_atoi(split[1]),
			ft_atoi(split[2]));
	if (color == -1)
		ft_error("Error\nInvalid color\n");
	return (color);
}
