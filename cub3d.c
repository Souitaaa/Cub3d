/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:49:04 by csouita           #+#    #+#             */
/*   Updated: 2025/02/19 20:04:10 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_xpm(t_data *data)
{
	int	len;

	len = ft_strlen(data->no) - 1;
	if (data->no[len - 1] != 'm' || data->no[len - 2] != 'p' || data->no[len
		- 3] != 'x' || data->no[len - 4] != '.')
	{
		ft_putstr_fd("Error\nInvalid file extension\n", 2);
		return (1);
	}
	len = ft_strlen(data->so) - 1;
	if (data->so[len - 1] != 'm' || data->so[len - 2] != 'p' || data->so[len
		- 3] != 'x' || data->so[len - 4] != '.')
	{
		ft_putstr_fd("Error\nInvalid file extension\n", 2);
		return (1);
	}
	len = ft_strlen(data->we) - 1;
	if (data->we[len - 1] != 'm' || data->we[len - 2] != 'p' || data->we[len
		- 3] != 'x' || data->we[len - 4] != '.')
	{
		ft_putstr_fd("Error\nInvalid file extension\n", 2);
		return (1);
	}
	len = ft_strlen(data->ea) - 1;
	if (data->ea[len - 1] != 'm' || data->ea[len - 2] != 'p' || data->ea[len
		- 3] != 'x' || data->ea[len - 4] != '.')
	{
		ft_putstr_fd("Error\nInvalid file extension\n", 2);
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
			// printf("line = %s\n", line);
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

int	count_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	parse_textures(t_data *data, int *i)
{
	int		fd;
	char	**split;
	char	**textures;
	char	*line;
	int		j;

	(void)i;
	fd = open(data->file, O_RDONLY);
	split = malloc(sizeof(char *) * (data->height + 1));
	textures = malloc(sizeof(char *) * (data->height + 1));
	line = get_next_line(fd);
	j = 0;
	while (line)
	{
		split = ft_split(line, ' ');
		printf("count split = %d\n", count_split(split));
		if (count_split(split) != 2)
		{
			printf("j == %d\n", j);
			printf("count_textures = %d\n", count_textures(data));
			if (j <= count_textures(data))
			{
				printf("j == %d\n", j);
				printf("count_textures = %d\n", count_textures(data));
				printf("dkhallllllllllllt\n");
				break ;
			}
			ft_putstr_fd("Error\nInvalssssid texture\n", 2);
			return (0);
		}
		else if (!ft_strcmp(split[0], "NO"))
		{
			data->no = ft_strdup(split[1]);
			data->no_key = ft_strdup(split[0]);
			// printf("data->no = %s\n", data->no);
		}
		else if (!ft_strcmp(split[0], "SO"))
		{
			data->so = ft_strdup(split[1]);
			data->so_key = ft_strdup(split[0]);
			// printf("data->so = %s\n", data->so);
		}
		else if (!ft_strcmp(split[0], "WE"))
		{
			data->we = ft_strdup(split[1]);
			data->we_key = ft_strdup(split[0]);
			// printf("data->we = %s\n", data->we);
		}
		else if (!ft_strcmp(split[0], "EA"))
		{
			data->ea = ft_strdup(split[1]);
			data->ea_key = ft_strdup(split[0]);
			// printf("data->ea = %s\n", data->ea);
		}
		printf("split[00000] = %s\n", split[0]);
		if (!ft_strcmp(split[0], "F") || !ft_strcmp(split[0], "C"))
		{
			textures = ft_split(split[1], ',');
			if (count_split(textures) != 3)
			{
				ft_putstr_fd("Error\nInvalid color\n", 2);
				return (0);
			}
			else if (!ft_strcmp(split[0], "F"))
			{
				data->f = ft_strdup(split[1]);
				data->f_key = ft_strdup(split[0]);
				// printf("data->f = %s\n", data->f);
			}
			else if (!ft_strcmp(split[0], "C"))
			{
				data->c = ft_strdup(split[1]);
				data->c_key = ft_strdup(split[0]);
				// printf("data->c = %s\n", data->c);
			}
		}
		free(line);
		for (int k = 0; split[k]; k++)
			free(split[k]);
		free(split);
		// for (int k = 0; textures[k]; k++)
		// 	free(textures[k]);
		// free(textures);
		// free(line);
		line = get_next_line(fd);
		j++;
	}
	// split[j] = NULL;
	close(fd);
	j = 0;
	// while (split[j])
	// {
	// 	for (int k = 0; split[j]; k++)
	// 		printf("%s\n", split[j]);
	// 	j++;
	// }
	// for (int k = 0; k < data->height; k++)
	// free(split[k]);
	// free(split);
	// free(line);
	return (1);
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
		ft_putstr_fd("Error\nInvalid file extension\n", 2);
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
	while (i < data->height)
	{
		printf("%s\n", data->map[i]);
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
					// check if the map is closed 11110 111
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
	if(check_xpm(data))
	{
		for (int k = 0; k < data->height; k++)
			free(data->map[k]);
		free(data->map);
		free(data);
		return (1);
	}
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
	// for (int k = 0; k < data->height; k++)
	//     free(data->map[k]);
	// free(data->map);
	// free(data);
	return (0);
}
