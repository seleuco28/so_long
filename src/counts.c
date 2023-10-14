/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:57:37 by alvelazq          #+#    #+#             */
/*   Updated: 2023/10/13 19:16:16 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_count_players(t_game *map)
{
	int	y;
	int	x;

	y = 0;
	map->player_num = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'P')
			{
				map->player_num++;
				map->player_y = y;
				map->player_x = x;
			}
			x++;
		}
		y++;
	}
	if (map->player_num != 1)
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
	map->coin_copy = map->coin; // no se puede quitar ya que iteramos una vez para ver si hay path y otra vez cada vez que hay movimientos
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
	map->movements = 0; //esto lo tengo que inicializar en algun sitio y eligo aqui
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
	map->exit = 0; // NECESITO PONERLO PARA EL VALID PATH
}
