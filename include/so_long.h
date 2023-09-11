/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:20:15 by alvelazq          #+#    #+#             */
/*   Updated: 2023/09/11 13:57:56 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

# include "../minilibx_opengl/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_game
{
	char			**map;
	char			**map_copy;
	unsigned long	y_max;
	unsigned long	x_max;
	int				player;
	int				player_x;
	int				player_y;
	int				coin;
	int				coin_copy;
	int				movements;
	int				exit;
	void			*mlx;
	void			*win;
	void			*img;
	int				img_w;
	int				img_h;

}t_game;

enum e_keycode
{
	M_UP = 13,
	M_DOWN = 1,
	M_RIGHT = 2,
	M_LEFT = 0,
	ESCAPE = 53,
};

///////////////////////////FUNCIONES GENERALES///////////////////////////

size_t	ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
void	ft_putstr(char *str);
char	*ft_itoa(int n);
///////////////////////////FUNCIONES PROPIAS///////////////////////////
int		ft_error_msg(char *message);
void	ft_check_args(int ac, char *av);
void	ft_map_creation(char *av, t_game *map);
int		ft_check_valid_chars(t_game *map);
void	ft_check_map_length(t_game *map);
void	ft_check_path(t_game *map, int y, int x);
void	ft_path_free_and_error_copy(t_game *map);
void	ft_free_map_principal(t_game *map);

void	ft_count_coins(t_game *map);
void	ft_count_players(t_game *map);
void	ft_count_exit(t_game *map);
void	ft_coin_exit_checker(t_game *map);

///////////////////////////FUNCIONES MLX///////////////////////////

void	draw_map(t_game *map);
int		ft_exit_game(t_game *map);
int		key_hook(int keycode, t_game *map);

///////////////////////////MOVES///////////////////////////
void	move_up(t_game *map);
void	move_down(t_game *map);
void	move_left(t_game *map);
void	move_right(t_game *map);

#endif