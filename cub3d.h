/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:35:09 by csouita           #+#    #+#             */
/*   Updated: 2025/02/19 19:02:50 by csouita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>

typedef struct s_data
{
    int height;
    int width ;
    char *file;
    char **map;
    char *no;
    char *so;
    char *we;
    char *ea;
    char *c;
    char *f;
    char *no_key;
    char *so_key;
    char *we_key;
    char *ea_key;
    char *c_key;
    char *f_key;
}   t_data;


void ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(char *s);
char	*get_next_line(int fd);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strdup(char *s1);
int	ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
int    ft_strcmp(char *s1, char *s2);
char	*ft_strrchr(char *s, int c);
long	ft_atoi(char *str);


#endif