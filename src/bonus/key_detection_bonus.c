/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_detection_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:18:34 by alvelazq          #+#    #+#             */
/*   Updated: 2023/09/11 12:04:49 by alvelazq         ###   ########.fr       */
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
		&& map->map[map->player_y - 1][map->player_x] != 'E')
		move_up(map);
	if (keycode == M_DOWN && map->map[map->player_y + 1][map->player_x] != '1'
		&& map->map[map->player_y + 1][map->player_x] != 'E')
		move_down(map);
	if (keycode == M_LEFT && map->map[map->player_y][map->player_x - 1] != '1'
		&& map->map[map->player_y][map->player_x - 1] != 'E')
		move_left(map);
	if (keycode == M_RIGHT && map->map[map->player_y][map->player_x + 1] != '1'
		&& map->map[map->player_y][map->player_x + 1] != 'E')
		move_right(map);
	return (0);
}
