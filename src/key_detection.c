/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_detection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:18:34 by alvelazq          #+#    #+#             */
/*   Updated: 2023/08/31 16:10:56 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_key_hook_aux(int keycode, t_game *map)
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
		printf("%s", "You Win!!!\n");
		ft_exit_game(map);
	}
}

int	key_hook(int keycode, t_game *map)
{
	ft_key_hook_aux(keycode, map);
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
