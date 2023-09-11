/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:13:49 by alvelazq          #+#    #+#             */
/*   Updated: 2023/09/11 12:02:42 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	limit_map(t_game *map, int y, int x)
{
	if ((y <= 0) || (y >= ((int)map->y_max) - 1)
		|| (x <= 0) || (x >= (int)map->x_max))
	{
		ft_putstr("Error\nThe map is not close!\n");
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
	if (map->map[y][x + 1] != '1' && map->map[y][x + 1] != '.'
		&& map->map[y][x + 1] != 'Q')
		(limit_map(map, y, x + 1), ft_check_path(map, y, x + 1));
	if (map->map[y][x - 1] != '1' && map->map[y][x - 1] != '.'
		&& map->map[y][x - 1] != 'Q')
		(limit_map(map, y, x - 1), ft_check_path(map, y, x - 1));
	if (map->map[y - 1][x] != '1' && map->map[y - 1][x] != '.'
		&& map->map[y - 1][x] != 'Q')
		(limit_map(map, y - 1, x), ft_check_path(map, y - 1, x));
	if (map->map[y + 1][x] != '1' && map->map[y + 1][x] != '.'
		&& map->map[y + 1][x] != 'Q')
		(limit_map(map, y + 1, x), ft_check_path(map, y + 1, x));
}

void	ft_coin_exit_checker(t_game *map)
{
	if (map->coin_copy != 0 || map->exit != 1)
	{
		ft_putstr("Error\nThere is no valid path!\n");
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
