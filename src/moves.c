/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:44:16 by alvelazq          #+#    #+#             */
/*   Updated: 2023/09/11 13:58:53 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_game *map)
{
	char	*text;

	if (map->map[map->player_y - 1][map->player_x] == 'C')
		map->coin--;
	map->map[map->player_y][map->player_x] = '0';
	map->map[map->player_y - 1][map->player_x] = 'P';
	map->player_y = map->player_y - 1;
	map->movements++;
	text = ft_itoa(map->movements);
	write(1, text, sizeof(text) - 1);
	write(1, "\n", 1);
	free(text);
	draw_map(map);
}

void	move_down(t_game *map)
{
	char	*text;

	if (map->map[map->player_y + 1][map->player_x] == 'C')
		map->coin--;
	map->map[map->player_y][map->player_x] = '0';
	map->map[map->player_y + 1][map->player_x] = 'P';
	map->player_y = map->player_y + 1;
	map->movements++;
	text = ft_itoa(map->movements);
	write(1, text, sizeof(text) - 1);
	write(1, "\n", 1);
	free(text);
	draw_map(map);
}

void	move_left(t_game *map)
{
	char	*text;

	if (map->map[map->player_y][map->player_x - 1] == 'C')
		map->coin--;
	map->map[map->player_y][map->player_x] = '0';
	map->map[map->player_y][map->player_x - 1] = 'P';
	map->player_x = map->player_x - 1;
	map->movements++;
	text = ft_itoa(map->movements);
	write(1, text, sizeof(text) - 1);
	write(1, "\n", 1);
	free(text);
	draw_map(map);
}

void	move_right(t_game *map)
{
	char	*text;

	if (map->map[map->player_y][map->player_x + 1] == 'C')
		map->coin--;
	map->map[map->player_y][map->player_x] = '0';
	map->map[map->player_y][map->player_x + 1] = 'P';
	map->player_x = map->player_x + 1;
	map->movements++;
	text = ft_itoa(map->movements);
	write(1, text, sizeof(text) - 1);
	write(1, "\n", 1);
	free(text);
	draw_map(map);
}
