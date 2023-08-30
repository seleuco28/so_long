/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:09:27 by alvelazq          #+#    #+#             */
/*   Updated: 2023/08/30 14:38:21 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void ft_draw(t_game *map, char *path, int x, int y)
{

    map->img = mlx_xpm_file_to_image(map->mlx, path, &map->img_w, &map->img_h);
    mlx_put_image_to_window(map->mlx, map->win, map->img, (x * 64), (y * 64));
}


void draw_map(t_game *map)
{
    int y;
    int x;
    y = 0;
    while (map->map[y])
    {
        x = 0;
        while (map->map[y][x])
        {
            ft_draw(map, "./sprites/floor.xpm", x , y);
            if  (map->map[y][x] == '1')
                ft_draw(map, "./sprites/wall.xpm", x , y);
            else if (map->map[y][x] == 'C')
                ft_draw(map, "./sprites/food.xpm", x , y);
            else if (map->map[y][x] == 'E')
                ft_draw(map, "./sprites/exit.xpm", x , y);
            else if (map->map[y][x] == 'P')
                ft_draw(map, "./sprites/player.xpm", x , y);
            x++;
        }
        y++;
    }


}

void	leaks(void)
{
	system("leaks -q so_long");
}

int main(int ac, char **av)
{
    t_game   map;
    //atexit(leaks);

    ft_check_args(ac, av[1]);
    ft_map_creation(av[1], &map);
    ft_check_valid_chars(&map);
    ft_count_elements(&map);
    ft_check_map_length(&map);
    ft_check_path(&map, map.player_y, map.player_x);
    ft_path_free_and_error_copy(&map);
    //VALE PONIENDO ESTO NO DA LEAKS
    //Y SIN PONERLO SON LEAKS DE NO LIBERAR EL MAPA
    //ft_free_map_principal(&map); //esto son pruebas mias para los leaks
    //printf("TODAS LAS EXCEPCIONES CORRECTAS\n");
    
    //HASTA AQUI NO DA LEAKS PERO ABAJO SI!!!!!!!!!!!!!

    map.mlx = mlx_init(); //This will establish a connection to the correct graphical system and will return a void * which holds the location of our current MLX instance
    
    // aqui ajusto la ventana para el tipo de mapa dado
    map.win = mlx_new_window(map.mlx, (map.x_max) * 64, (map.y_max) * 64 ,"The so_long game"); //will return a pointer to the window we have just created
    draw_map(&map);
    mlx_hook(map.win, 17, 1L << 0, ft_exit_game, &map); //esto es para que cuando le des a la X de arriba el programa pare

    mlx_hook(map.win, 2, 1L << 0, key_hook, &map);
    mlx_loop(map.mlx); //esto es para que renderize
    
    return (0);
}