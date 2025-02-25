/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:49:04 by csouita           #+#    #+#             */
/*   Updated: 2025/02/25 19:00:17 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\v'
			&& line[i] != '\f' && line[i] != '\r' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}


int	count_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int  handle_colors(char *line)
{
	int i = 0 ;
	int count = 0;
	while(line[i])
	{
		if(line[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
	{
		ft_putstr_fd("Error\nInvaliiiiiiid color\n", 2);
		exit(1);
	}
	char **split = ft_split(line,',');

	if(count_split(split) != 3)
	{
		ft_putstr_fd("Error\nInvalid colrrrrr\n", 2);
		exit(1);
	}
	int color = create_trgb(1, ft_atoi(split[0]), ft_atoi(split[1]), ft_atoi(split[2]));
	if (color == -1)
	{
		ft_putstr_fd("Error\nInvalid color",2);
		exit(1);
	}
	return color;
}

int	check_xpm(t_data *data)
{
	int	len;
	
	len = ft_strlen(data->no) ;
	if (data->no[len - 1] != 'm' || data->no[len - 2] != 'p' || data->no[len
		- 3] != 'x' || data->no[len - 4] != '.')
	{	
		ft_putstr_fd("Error\nInvalid file extension1\n", 2);
		return (1);
	}
	len = ft_strlen(data->so);
	if (data->so[len - 1] != 'm' || data->so[len - 2] != 'p' || data->so[len
		- 3] != 'x' || data->so[len - 4] != '.')
	{
		ft_putstr_fd("Error\nInvalid file extension2\n", 2);
		return (1);
	}
	len = ft_strlen(data->we);
	if (data->we[len - 1] != 'm' || data->we[len - 2] != 'p' || data->we[len
		- 3] != 'x' || data->we[len - 4] != '.')
	{
		ft_putstr_fd("Error\nInvalid file extension3\n", 2);
		return (1);
	}
	len = ft_strlen(data->ea);
	if (data->ea[len - 1] != 'm' || data->ea[len - 2] != 'p' || data->ea[len
		- 3] != 'x' || data->ea[len - 4] != '.')
	{
		ft_putstr_fd("Error\nInvalid file extension4\n", 2);
		return (1);
	}
	return (0);
}

int	check_whitespace(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\v'
		|| line[i] == '\f' || line[i] == '\r')
		i++;
	return (i);
}

int	parse_element(t_data *data, int *i)
{
	if (ft_strncmp(data->map[*i], "NO", 2) == 0 || ft_strncmp(data->map[*i],
			"SO", 2) == 0 || ft_strncmp(data->map[*i], "WE", 2) == 0
		|| ft_strncmp(data->map[*i], "EA", 2) == 0 || ft_strncmp(data->map[*i],
			"F", 1) == 0 || ft_strncmp(data->map[*i], "C", 1) == 0)
	{
		return (1);
	}
	return (0);
}

int	count_textures(t_data *data)
{
	int		count;
	int		fd;
	char	*line;

	count = 0;
	fd = open(data->file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (!check_empty(line))
		{
			free(line);
			line = get_next_line(fd);
		}
		if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
			|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0
			|| ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
		{
			count++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

int	count_line(t_data *data)
{
	int		fd;
	char	*line;
	int		line_count;

	fd = open(data->file, O_RDONLY);
	line = get_next_line(fd);
	line_count = 0;
	while (line)
	{
		if (check_empty(line))
		{
			free(line);
			line = get_next_line(fd);
		}
		line_count++;
	}
	close(fd);
	return (line_count);
}

int check_player_valid_pos(t_data *data)
{

	int i = data->first_line_in_map;
	int j = 0;
	int count = 0;
	while (i < data->height)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S' || data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				data->player_x = i;
				data->player_y = j;
				count++;
				printf("Count = %d\n", count);
			}
			j++;
		}
		i++;
	}
	if (count != 1)
	{
		ft_putstr_fd("Error\nInvalid player position\n", 2);
		exit(1);
	}
	return 0;
}

int	parse_textures(t_data *data, int *i)
{
	int		fd;
	char	**split;
	char	*line;
	int		j;

	(void)i;
	fd = open(data->file, O_RDONLY);
	split = malloc(sizeof(char *) * (data->height + 1));
	line = get_next_line(fd);
	j = 0;
	while (line)
	{
		split = ft_split00(line);
		if (!check_empty(line))
		{
			free(line);
			line = get_next_line(fd);
			data->first_line_in_map++;
			continue ;
		}
		if (count_split(split) != 2)
		{
			if (j == 6)
				break ;
			ft_putstr_fd("Error\nInvalssssid texture\n", 2);
			exit(1);
		}
		else if (!ft_strcmp(split[0], "NO"))
		{
			data->first_line_in_map++;
			data->no = ft_strdup(split[1]);
			data->no_key = ft_strdup(split[0]);
		}
		else if (!ft_strcmp(split[0], "SO"))
		{
			data->first_line_in_map++;
			data->so = ft_strdup(split[1]);
			data->so_key = ft_strdup(split[0]);
		}
		else if (!ft_strcmp(split[0], "WE"))
		{
			data->first_line_in_map++;
			data->we = ft_strdup(split[1]);
			data->we_key = ft_strdup(split[0]);
		}
		else if (!ft_strcmp(split[0], "EA"))
		{
			data->first_line_in_map++;
			data->ea = ft_strdup(split[1]);
			data->ea_key = ft_strdup(split[0]);
		}
		else if (!ft_strcmp(split[0], "F"))
		{
			data->first_line_in_map++;
			data->color_f = handle_colors(split[1]);
			data->f = ft_strdup(split[1]);
			data->f_key = ft_strdup(split[0]);
		}
		else if (!ft_strcmp(split[0], "C"))
		{
			data->first_line_in_map++;
			data->color_c = handle_colors(split[1]);
			data->c = ft_strdup(split[1]);
			data->c_key = ft_strdup(split[0]);
		}
		free(line);
		for (int k = 0; split[k]; k++)
			free(split[k]);
		free(split);

		line = get_next_line(fd);
		j++;
		
	}
	close(fd);
	j = 0;
	return (1);
}

void first_line_in_map(t_data *data)
{
	int i = data->first_line_in_map;
	while (data->map[i])
	{
		if (data->map[i])
			return;
		if (!check_empty(data->map[i]))
		{
			data->first_line_in_map++;
			i++;
		}
		else 
			i++;
	}
}

int	is_valide2(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ' || c == '\n' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	is_valide(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int first_and_last_lines_check(t_data *data)
{
	int i = data->first_line_in_map - 1;
	int j = 0;
	while (data->map[i][j])
	{
		// if (check_empty(data->map[i]))
		// {
		// 	i++;
		// 	continue ;
		// }
		if (data->map[i][j] != '1' && (data->map[i][j] != ' ' || (!(data->map[i][j] >= 9 && data->map[i][j] <= 13))) && data->map[i][j] != '\n')
		{
			ft_putstr_fd("Error\nMap is not clossssssssssed\n", 2);
			return (1);
		}
		j++;
	}
	i = data->height - 1;
	j = 0;
	while (data->map[i][j])
	{
		// if (check_empty(data->map[i]))
		// {
		// 	i++;
		// 	continue ;
		// }
		if (data->map[i][j] != '1' && (data->map[i][j] != ' ' || (!(data->map[i][j] >= 9 && data->map[i][j] <= 13))) && data->map[i][j] != '\n')
		{
			ft_putstr_fd("Error\nMap is not clddddosed\n", 2);
			return (1);
		}
		j++;
	}
	return (0);
}

int	main(int ac, char *av[])
{
	int		i;
	t_data	*data;
	int		len;
	int		fd;
	char	*line;
	int		j;

	i = 0;
	data = malloc(sizeof(t_data));
	if (!data)
	{
		ft_putstr_fd("Error\nMemory allocation failed\n", 2);
		return (1);
	}
	ft_memset(data, 0, sizeof(t_data));
	if (ac != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		return (1);
	}
	data->file = av[1];
	len = ft_strlen(av[1]);
	if (len < 4 || av[1][len - 1] != 'b' || av[1][len - 2] != 'u' || av[1][len
		- 3] != 'c' || av[1][len - 4] != '.')
	{
		ft_putstr_fd("Error\nInvalid path extension\n", 2);
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nInvalid file\n", 2);
		return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	data->height = i;
	i = 0;
	close(fd);
	fd = open(av[1], O_RDONLY);
	data->map = malloc(sizeof(char *) * (data->height + 1));
	if (!data->map)
	{
		ft_putstr_fd("Error\nMemory allocation failed\n", 2);
		free(data);
		return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		data->map[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	i = 0;
	j = 0;
	while (i < data->height)
	{
		if (parse_element(data, &i))
		{
			i++;
			continue ;
		}
		j = 0;
		while (data->map[i][j])
		{
			if (!is_valide2(data->map[i][j]))
			{
				ft_putstr_fd("Error\nInvalid character in map\n", 2);
				for (int k = 0; k < data->height; k++)
					free(data->map[k]);
				free(data->map);
				free(data);
				return (1);
			}
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < data->height)
	{
		if (parse_element(data, &i))
		{
			i++;
			continue ;
		}
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0')
			{
				if (!check_empty(data->map[i + 1]) || !check_empty(data->map[i
						- 1]) || !check_empty(data->map[i] + j + 1)
					|| !check_empty(data->map[i] + j - 1))
				{
					ft_putstr_fd("Error\nMap wwwis not closed\n", 2);
					exit(1);
				}
				if (i == 0 || i == data->height - 1 || j == 0
					|| j == (int)ft_strlen(data->map[i]) - 1
					|| !is_valide(data->map[i][j + 1])
					|| !is_valide(data->map[i][j - 1]) || !is_valide(data->map[i
						+ 1][j]) || !is_valide(data->map[i - 1][j]))
				{
					ft_putstr_fd("Error\nMap is not closed\n", 2);
					for (int k = 0; k < data->height; k++)
						free(data->map[k]);
					free(data->map);
					free(data);
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	i = 0;
	parse_textures(data, &i);
	if (check_xpm(data))
	{
		for (int k = 0; k < data->height; k++)
			free(data->map[k]);
		free(data->map);
		free(data);
		return (1);
	}
	first_line_in_map(data);
	printf("first line in map = %d\n", data->first_line_in_map);
	if(first_and_last_lines_check(data))
	{
		for (int k = 0; k < data->height; k++)
			free(data->map[k]);
		free(data->map);
		free(data);
		return (1);
	}
	check_player_valid_pos(data);
	// if (check_player_pos(data))
	// {
	// 	for (int k = 0; k < data->height; k++)
	// 		free(data->map[k]);
	// 	free(data->map);
	// 	free(data);
	// 	return (1);
	// }
	i = 0;
	// while(data->map[i])
	// {
	// 	printf("%s\n", data->map[i]);
	// 	i++;
	// }
	printf("NO = %s\n", data->no);
	printf("SO = %s\n", data->so);
	printf("WE = %s\n", data->we);
	printf("EA = %s\n", data->ea);
	printf("F = %s\n", data->f);
	printf("C = %s\n", data->c);
	printf("NO_KEY = %s\n", data->no_key);
	printf("SO_KEY = %s\n", data->so_key);
	printf("WE_KEY = %s\n", data->we_key);
	printf("EA_KEY = %s\n", data->ea_key);
	printf("F_KEY = %s\n", data->f_key);
	printf("C_KEY = %s\n", data->c_key);
	printf("color_f = %d\n", data->color_f);
	printf("color_c = %d\n", data->color_c);
	return (0);
}
