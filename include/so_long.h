/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:20:15 by alvelazq          #+#    #+#             */
/*   Updated: 2023/08/17 10:12:19 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_game
{
    char **map;
    char **map_copy;
    int y_max;
    int x_max;
    int player;
    int player_x;
    int player_y;
    int coin;
    int coin_copy;
    int exit;

}t_game;



///////////////////////////FUNCIONES GENERALES///////////////////////////
//int	ft_printf(char const *str, ...);
size_t  ft_strlen(char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);

///////////////////////////FUNCIONES PROPIAS///////////////////////////
int ft_error_msg(char *message);
void ft_check_args(int ac, char *av);
void ft_map_creation(char *av, t_game *map);
int ft_check_valid_chars(t_game *map);
void	ft_count_elements(t_game *map);
void ft_check_map_length(t_game *map);
void ft_check_walls(t_game *map);
void	ft_check_path(t_game *map, int y, int x);
void	ft_path_free_and_error(t_game *map);
#endif