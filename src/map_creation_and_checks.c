/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation_and_checks.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:10:23 by alvelazq          #+#    #+#             */
/*   Updated: 2023/08/17 11:12:23 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void ft_map_creation(char *av, t_game *map)
{
    int map_fd;
    char *temp_line;
    char *array_1;
    
    map_fd = open(av, O_RDONLY);
    if (!map_fd || map_fd == -1)
        ft_error_msg("File descriptor not found");
    array_1 = ft_strdup("");
    while(1)
    {
        temp_line = get_next_line(map_fd); // GNL como funcion que  te permitirá leer el contenido del archivo hacia el que apunta el file descriptor,
                                            //línea a línea, hasta el final.
        if (temp_line == NULL)
            break;
        array_1 = ft_strjoin(array_1, temp_line);
        free(temp_line);
    }

    map->map = ft_split(array_1, '\n');
	map->map_copy = ft_split(array_1, '\n');
    free(array_1);
    // ESTO AUN NO SE SI FUNCIONA O NO
}

int ft_check_valid_chars(t_game *map)
{
    char **read;
    int x;
    int y;

    read = map->map;
    y = 0;
    while (read[y])
    {
        x = 0;
        while (read[y][x])
        {
            if (read[y][x] != '0' && read[y][x] != '1' && read[y][x] != 'C' && read[y][x] != 'P' && read[y][x] != 'E')
                ft_error_msg("Unexpected char type\n");
            x++;
        }
        y++;
    }
    return (1);
}

// Only function it has, count how many coins, players and exits are in the map
void	ft_count_elements(t_game *map)
{
	int	y;
	int	x;

	y = 0;
	map->player = 0;
    map->coin = 0;
    map->exit = 0;
    
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
			if (map->map[y][x] == 'C')
				map->coin++;
			if (map->map[y][x] == 'E')
				map->exit++;
			x++;
		}
		y++;
	}
	map->coin_copy = map->coin;
	if (map->player != 1 || map->exit != 1 || map->coin == 0)
		ft_error_msg("Falta jugador o exit o coins (o varias)\n");
}

void ft_check_map_length(t_game *map) 
{
    int x;
    int y;
    x = 0;
    y = 0;
    map->x_max = ft_strlen(map->map[x]); //dame el len del puntero, uno cualquiera porque todos tienen la misma len
	map->y_max = 0;
	while (map->map[y]) //mientras exista un puntero a puntero hay una "y" más
	{
		map->y_max++;
		y++;
	}
    //printf("El mapa es de %d por %d\n", map->x_max , map->y_max);
}

void ft_check_walls(t_game *map) //aqui hay que meterle una funcion para ver si es rectangular¿?
{
	int	x;
	int	y;
	y = 0;
	while (y < map->y_max)
	{
		x = 0;
		while (x < map->x_max)
		{
			if (map->map[0][x] != '1' || map->map[map->y_max - 1][x] != '1'
			|| map->map[y][0] != '1' || map->map[y][map->x_max - 1] != '1')
				ft_error_msg("Borders aren't correct\n");
			x++;
		}
		y++;
	}

}