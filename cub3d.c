/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:49:04 by csouita           #+#    #+#             */
/*   Updated: 2025/02/14 23:47:41 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int parse_element(t_data *data ,  int *i)
{
    if (ft_strncmp(data->map[*i], "NO", 2) == 0 || ft_strncmp(data->map[*i], "SO", 2) == 0 ||
            ft_strncmp(data->map[*i], "WE", 2) == 0 || ft_strncmp(data->map[*i], "EA", 2) == 0 ||
            ft_strncmp(data->map[*i], "F", 1) == 0 || ft_strncmp(data->map[*i], "C", 1) == 0)
        {
            i++;
            return (1);
        } 
    return (0);
}

int is_valide2(char c)
{
    if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == ' ' || c == '\n' || (c >= 9 && c <= 13) ) 
        return (1);
    return (0);
}


int is_valide(char c)
{
    if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
        return (1);
    return (0);
}

int main(int ac, char *av[])
{   
    int i = 0;
    t_data *data  = malloc(sizeof(t_data));
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
    int len = ft_strlen(av[1]);
    if (len < 4 || av[1][len - 1] != 'b' || av[1][len - 2] != 'u' || av[1][len - 3] != 'c' || av[1][len - 4] != '.')
    {
        ft_putstr_fd("Error\nInvalid file extension\n", 2);
        return (1);
    }

    int fd = open(av[1], O_RDONLY);
    if (fd == -1)
    {
        ft_putstr_fd("Error\nInvalid file\n", 2);
        return (1);
    }
    char *line = get_next_line(fd);
    while(line)
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
    while(line)
    {
        data->map[i] = ft_strdup(line);
        i++;
        free(line);
        line = get_next_line(fd);
    }
    i = 0 ;
    while(i < data->height)
    {   
        printf("%s\n", data->map[i]);
        i++;
    }
    i = 0;
    int j = 0;
    
    while(i < data->height)
    {
        if(parse_element(data, &i))
        {
            i++;
            continue;
        }
        j = 0;
        while(data->map[i][j])
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
    
    i = 0 ;
    j = 0;
    while (i < data->height)
    {
        if(parse_element(data, &i))
        {
            i++;
            continue;
        }
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == '0')
            {
                if (i == 0 || i == data->height - 1 || j == 0 || j == (int)ft_strlen(data->map[i]) - 1 ||
                    !is_valide(data->map[i][j + 1]) || !is_valide(data->map[i][j - 1]) ||
                    !is_valide(data->map[i + 1][j]) || !is_valide(data->map[i - 1][j]))
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

    for (int k = 0; k < data->height; k++)
        free(data->map[k]);
    free(data->map);
    free(data);
    return (0);
}

