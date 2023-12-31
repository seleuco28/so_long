/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:09:27 by alvelazq          #+#    #+#             */
/*   Updated: 2023/11/23 21:48:22 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_draw(t_game *map, char *path, int x, int y)
{
	map->img = mlx_xpm_file_to_image(map->mlx, path, &map->img_w, &map->img_h);
	if (!map->img) //protegido lo del relative path, pero no se comprobarlo!!
	{
		ft_putstr("ERROR: Relative path protected\n");
		exit(0);
	}
	mlx_put_image_to_window(map->mlx, map->win, map->img, (x * 64), (y * 64));
}

void	draw_map(t_game *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			ft_draw(map, "./sprites/Floor.xpm", x, y);
			if (map->map[y][x] == '1')
				ft_draw(map, "./sprites/Wall.xpm", x, y);
			else if (map->map[y][x] == 'C')
				ft_draw(map, "./sprites/Food.xpm", x, y);
			else if (map->map[y][x] == 'E')
				ft_draw(map, "./sprites/Exit.xpm", x, y);
			else if (map->map[y][x] == 'P')
				ft_draw(map, "./sprites/player_1.xpm", x, y);
			x++;
		}
		y++;
	}
}

void	leaks(void)
{
	system("leaks -q so_long");
}

int	main(int ac, char **av)
{
	t_game	map;

	//atexit(leaks);

	ft_check_args(ac, av[1]);
	ft_map_creation(av[1], &map);
	ft_check_valid_chars(&map);
	ft_count_coins(&map);
	ft_count_players(&map);
	ft_count_exit(&map);
	ft_check_if_rect(&map);
	ft_check_path_pec_excepction(&map, map.player_y, map.player_x);
	ft_check_path(&map, map.player_y, map.player_x);
	ft_coin_exit_checker(&map);
	ft_free_map_principal(&map);
	ft_map_creation(av[1], &map);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, (map.x_max) * 64,
			(map.y_max) * 64, "so_long");
	draw_map(&map);
	mlx_hook(map.win, 17, 0, ft_exit_game, &map);
	mlx_key_hook(map.win, key_hook, &map);
	mlx_loop(map.mlx);
	return (0);
}
