/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counts_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:57:37 by alvelazq          #+#    #+#             */
/*   Updated: 2023/09/11 12:03:33 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

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
	{
		ft_putstr("ERROR: Missing or too much players.\n");
		exit(0);
	}
}

void	ft_count_coins(t_game *map)
{
	int	y;
	int	x;

	map->coin = 0;
	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (map->map[y][x] == 'C')
				map->coin++;
		}
	}
	map->coin_copy = map->coin;
	if (map->coin == 0)
	{
		ft_putstr("ERROR: Coins missing\n");
		exit(0);
	}
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
	{
		ft_putstr("The exit is missing or there is more than one.\n");
		exit(0);
	}
	map->exit = 0;
}

void	ft_count_enemies(t_game *map)
{
	int	y;
	int	x;

	y = 0;
	map->enemy = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'Q')
				map->enemy++;
			x++;
		}
		y++;
	}
	if (map->enemy != 1)
	{
		ft_putstr("ERROR: There must be at least one enemy.\n");
		exit(0);
	}
}
