/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:43:24 by csouita           #+#    #+#             */
/*   Updated: 2025/03/04 00:49:29 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_no_texture(t_data *data, char **split)
{
	data->first_line_in_map++;
	data->no = ft_strdup(split[1]);
	data->no_key = ft_strdup(split[0]);
}

void	set_so_texture(t_data *data, char **split)
{
	data->first_line_in_map++;
	data->so = ft_strdup(split[1]);
	data->so_key = ft_strdup(split[0]);
}

void	set_we_texture(t_data *data, char **split)
{
	data->first_line_in_map++;
	data->we = ft_strdup(split[1]);
	data->we_key = ft_strdup(split[0]);
}

void	set_ea_texture(t_data *data, char **split)
{
	data->first_line_in_map++;
	data->ea = ft_strdup(split[1]);
	data->ea_key = ft_strdup(split[0]);
}

void	set_floor_and_ceiling_color(t_data *data, char **split, int i)
{
	if (i == 1)
	{
		data->first_line_in_map++;
		data->color_f = handle_colors(split[1]);
		data->f = ft_strdup(split[1]);
		data->f_key = ft_strdup(split[0]);
	}
	else
	{
		data->first_line_in_map++;
		data->color_c = handle_colors(split[1]);
		data->c = ft_strdup(split[1]);
		data->c_key = ft_strdup(split[0]);
	}
}
