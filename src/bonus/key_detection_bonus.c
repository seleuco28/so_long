/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_detection_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:18:34 by alvelazq          #+#    #+#             */
/*   Updated: 2023/09/08 12:31:37 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	ft_key_hook_exit(int keycode, t_game *map)
{
	if (keycode == ESCAPE)
		ft_exit_game(map);
	if (map->coin == 0
		&& ((keycode == M_RIGHT
				&& map->map[map->player_y][map->player_x + 1] == 'E')
		|| (keycode == M_DOWN
			&& map->map[map->player_y + 1][map->player_x] == 'E')
		|| (keycode == M_LEFT
				&& map->map[map->player_y][map->player_x - 1] == 'E')
		|| (keycode == M_UP
				&& map->map[map->player_y - 1][map->player_x] == 'E')))
	{
		ft_putstr("You Win!!!\n");
		ft_exit_game(map);
	}
}

void	ft_key_hook_enemy(int keycode, t_game *map)
{
	//if (keycode == ESCAPE) //creo que esta funcion sobra (ya esta contemplada arriba)
	//	ft_exit_game(map);
	if ((keycode == M_RIGHT
				&& map->map[map->player_y][map->player_x + 1] == 'Q')
		|| (keycode == M_DOWN
			&& map->map[map->player_y + 1][map->player_x] == 'Q')
		|| (keycode == M_LEFT
				&& map->map[map->player_y][map->player_x - 1] == 'Q')
		|| (keycode == M_UP
				&& map->map[map->player_y - 1][map->player_x] == 'Q'))
	{
		ft_putstr("You loose :(\n");
		ft_exit_game(map);
	}
}

int	key_hook(int keycode, t_game *map)
{
	ft_key_hook_exit(keycode, map);
	ft_key_hook_enemy(keycode, map);
	if (keycode == M_UP && map->map[map->player_y - 1][map->player_x] != '1'
		&& map->map[map->player_y - 1][map->player_x] != 'E') //EN REALIDAD NO HARIAN FALTA NI ESTA LINEA NI LAS DE ABAJO PORQUE LO CONTEMPLO EN LAS FUNCIONES AUXILIARES DE ARRIBA
		//&& map->map[map->player_y - 1][map->player_x] != 'Q') //aqui habria que poner tambien, que no te topes con el enemigo
		move_up(map);
	if (keycode == M_DOWN && map->map[map->player_y + 1][map->player_x] != '1'
		&& map->map[map->player_y + 1][map->player_x] != 'E')
		//&& map->map[map->player_y + 1][map->player_x] != 'Q')
		move_down(map);
	if (keycode == M_LEFT && map->map[map->player_y][map->player_x - 1] != '1'
		&& map->map[map->player_y][map->player_x - 1] != 'E')
		//&& map->map[map->player_y][map->player_x - 1] != 'Q')
		move_left(map);
	if (keycode == M_RIGHT && map->map[map->player_y][map->player_x + 1] != '1'
		&& map->map[map->player_y][map->player_x + 1] != 'E')
		//&& map->map[map->player_y][map->player_x + 1] != 'Q')
		move_right(map);
	return (0);
}
