/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:57:37 by alvelazq          #+#    #+#             */
/*   Updated: 2023/08/31 17:43:21 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_count_players(t_game *map)
{
	int	y;
	int	x;

	y = 0;
	map->player = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'P')
			{
				map->player++;
				map->player_y = y;
				map->player_x = x;
			}
			x++;
		}
		y++;
	}
	if (map->player != 1)
		ft_error_msg("ERROR: Player missing or too much\n");
}

void	ft_count_coins(t_game *map)
{
	int	y;
	int	x;

	y = 0;
	map->coin = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'C')
				map->coin++;
			x++;
		}
		y++;
	}
	map->coin_copy = map->coin;
	if (map->coin == 0)
		ft_error_msg("ERROR: Coins missing\n");
}

void	ft_count_exit(t_game *map)
{
	int	y;
	int	x;

	y = 0;
	map->exit = 0;
	map->movements = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'E')
				map->exit++;
			x++;
		}
		y++;
	}
	if (map->exit != 1)
		ft_error_msg("The exit is missing\n");
}
