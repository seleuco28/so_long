/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:13:49 by alvelazq          #+#    #+#             */
/*   Updated: 2023/11/23 21:50:01 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	limit_map(t_game *map, int y, int x)
{
	if ((y <= 0) || (y >= ((int)map->y_max) - 1)
		|| (x <= 0) || (x >= (int)map->x_max))
	{
		ft_putstr("Error: The map is not close!\n");
		exit(0);
	}
}

void	ft_check_path_pec_excepction(t_game *map, int y, int x)
{
	if ((map->map[y][x] == 'P' && map->map[y][x + 1] == 'E'
		&& map->map[y][x + 2] == 'C')
		|| (map->map[y][x] == 'P' && map->map[y][x - 1] == 'E'
		&& map->map[y][x - 2] == 'C')
		|| (map->map[y][x] == 'P' && map->map[y + 1][x] == 'E'
		&& map->map[y + 2][x] == 'C')
		|| (map->map[y][x] == 'P' && map->map[y - 1][x] == 'E'
		&& map->map[y - 2][x] == 'C'))
	{
		ft_putstr("Error: You can't finish the game!!\n");
		exit(0);
	}
}

void	ft_check_path(t_game *map, int y, int x)
{
	char	p;

	p = map->map[y][x];
	if (p == 'C')
		map->coin_copy--;
	else if (p == 'E')
		map->exit++;
	map->map[y][x] = '.';
	if (map->map[y][x + 1] != '1' && map->map[y][x + 1] != '.')
		(limit_map(map, y, x + 1), ft_check_path(map, y, x + 1));
	if (map->map[y][x - 1] != '1' && map->map[y][x - 1] != '.')
		(limit_map(map, y, x - 1), ft_check_path(map, y, x - 1));
	if (map->map[y - 1][x] != '1' && map->map[y - 1][x] != '.')
		(limit_map(map, y - 1, x), ft_check_path(map, y - 1, x));
	if (map->map[y + 1][x] != '1' && map->map[y + 1][x] != '.')
		(limit_map(map, y + 1, x), ft_check_path(map, y + 1, x));
}

void	ft_coin_exit_checker(t_game *map)
{
	if (map->coin_copy != 0 || map->exit != 1)
	{
		ft_putstr("Error: There is no valid path!\n");
		exit(0);
	}
}

void	ft_free_map_principal(t_game *map)
{
	int	i;

	i = 0;
	while (map->map[i] != NULL)
		free(map->map[i++]);
	free(map->map);
}
