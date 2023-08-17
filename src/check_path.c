/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:13:49 by alvelazq          #+#    #+#             */
/*   Updated: 2023/08/17 11:11:46 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_check_path(t_game *map, int y, int x)
{
	char	*p;

	p = &map->map_copy[y][x];
	if (*p != '1')
	{
		if (*p == 'C')
			map->coin_copy--;
		*p = '1';
		if (map->map_copy[y][x + 1] != '1')
			ft_check_path(map, y, x + 1);
		if (map->map_copy[y][x - 1] != '1')
			ft_check_path(map, y, x - 1);
		if (map->map_copy[y - 1][x] != '1')
			ft_check_path(map, y - 1, x);
		if (map->map_copy[y + 1][x] != '1')
			ft_check_path(map, y + 1, x);
	}
}

// Frees all the copy of the map and checks all the coins have been collected
void	ft_path_free_and_error(t_game *map)
{
	int	i;

	i = 0;
	while (map->map_copy[i])
	{
		free(map->map_copy[i]);
		i++;
	}
	free(map->map_copy);
	if (map->coin_copy != 0 || map->exit != 1) //aqui tengo problemas con el coin_copy
		//printf("El valor del coin copy es: %d\n", map->coin_copy);
		ft_error_msg("Error\nThere is no valid path!\n");
}