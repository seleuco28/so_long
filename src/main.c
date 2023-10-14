/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:09:27 by alvelazq          #+#    #+#             */
/*   Updated: 2023/10/14 10:53:24 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_draw(t_game *map, char *path, int x, int y)
{
	map->img = mlx_xpm_file_to_image(map->mlx, path, &map->img_w, &map->img_h); //aqui tengo la imagen
	mlx_put_image_to_window(map->mlx, map->win, map->img, (x * 64), (y * 64)); //aqui pone la imagen en un punto concreto de la ventana
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

	ft_check_args(ac, av[1]); //checkeado
	ft_map_creation(av[1], &map); //checkeado
	ft_check_valid_chars(&map); //checkeado
	ft_count_coins(&map); //checkeado, no se puede quitar la variable coin_copy REVISARLO LUEGO OTRA VEZ
	ft_count_players(&map); //checkeado
	ft_count_exit(&map); //checkeado
	ft_check_if_rect(&map); //checkeado
	ft_check_path(&map, map.player_y, map.player_x); //checkeado
	ft_coin_exit_checker(&map); //checkeado, esta es la que resuelve la de arriba
	ft_free_map_principal(&map); // liberas el mapa pintado por flood_fill
	ft_map_creation(av[1], &map); //y lo vuelves a crear
	map.mlx = mlx_init(); 
	//This will establish a connection to the correct graphical system and will return a void * which holds the location of our current MLX instance.
	map.win = mlx_new_window(map.mlx, (map.x_max) * 64,
			(map.y_max) * 64, "so_long");
	//we will simply call the mlx_new_window function, which will return a pointer to the window we have just created.
	draw_map(&map); //checkeado
	//mlx_hook(map.win, 17, 0, ft_exit_game, &map); //no me hace falta porque ya lo he metido en la siguiente funcion
	mlx_key_hook(map.win, key_hook, &map);
	mlx_loop(map.mlx); //to initiate the window rendering: Renderizar una imagen se refiere al proceso de generar una representación visual a partir de datos tridimensionales o de modelo en un entorno de gráficos por computadora.
	return (0);
}
