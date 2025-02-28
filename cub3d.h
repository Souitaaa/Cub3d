/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouita <csouita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:35:09 by csouita           #+#    #+#             */
/*   Updated: 2025/02/28 04:51:35 by csouita          ###   ########.fr       */
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
#include <mlx.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>
#include <X11/X.h>

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
    int color_f;
    int color_c;
    int player_x;
    int player_y;
    int first_line_in_map;
    int last_line_in_map;
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
int	create_trgb(int t, int r, int g, int b);
char	**ft_split00(char *s);
int	ft_isalnum(int c);


#endif