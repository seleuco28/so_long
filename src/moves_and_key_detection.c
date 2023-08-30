/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_and_key_detection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:44:16 by alvelazq          #+#    #+#             */
/*   Updated: 2023/08/30 11:42:14 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void move_up(t_game *map)
{
	if (map->map[map->player_y - 1][map->player_x] == 'C')
		map->coin--;    
    map->map[map->player_y][map->player_x] = '0'; //donde estas pinta suelo 
    map->map[map->player_y - 1][map->player_x] = 'P'; //la siguiente pinta player
    map->player_y = map->player_y - 1; // y actualiza el mapa
    map->movements++; //suma movements
    printf("%d\n", map->movements);
    draw_map(map);
}

void move_down(t_game *map)
{
    if (map->map[map->player_y + 1][map->player_x] == 'C')
        map->coin--;
    map->map[map->player_y][map->player_x] = '0';
    map->map[map->player_y + 1][map->player_x] = 'P';
    map->player_y = map->player_y + 1;
    map->movements++;
    printf("%d\n", map->movements);
    draw_map(map);
}

void move_left(t_game *map)
{
    if (map->map[map->player_y][map->player_x - 1] == 'C')
        map->coin--;
    map->map[map->player_y][map->player_x] = '0';
    map->map[map->player_y][map->player_x - 1] = 'P';
    map->player_x = map->player_x - 1;
    map->movements++;
    printf("%d\n", map->movements);
    draw_map(map);
}

void move_right(t_game *map)
{
    if (map->map[map->player_y][map->player_x + 1] == 'C')
        map->coin--;
    map->map[map->player_y][map->player_x] = '0';
    map->map[map->player_y][map->player_x + 1] = 'P';
    map->player_x = map->player_x + 1;
    map->movements++;
    printf("%d\n" , map->movements);
    draw_map(map);
}

int key_hook(int keycode, t_game *map)
{
    if (keycode == 53)
        ft_exit_game(map);
    if (map->coin == 0
		&& ((keycode == M_RIGHT && map->map[map->player_y][map->player_x + 1] == 'E')
		|| (keycode == M_DOWN && map->map[map->player_y + 1][map->player_x] == 'E')
		|| (keycode == M_LEFT && map->map[map->player_y][map->player_x - 1] == 'E')
		|| (keycode == M_UP && map->map[map->player_y - 1][map->player_x] == 'E')))
	{
		printf("\n%s", "You Win!!!");
		ft_exit_game(map);
	}
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
    return(0);
}