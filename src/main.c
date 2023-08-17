/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:09:27 by alvelazq          #+#    #+#             */
/*   Updated: 2023/08/17 11:16:40 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(int ac, char **av)
{
    t_game   map;

    ft_check_args(ac, av[1]);
    ft_map_creation(av[1], &map);
    ft_check_valid_chars(&map);
    ft_count_elements(&map);
    ft_check_map_length(&map);
    ft_check_walls(&map);
    ft_check_path(&map, map.player_y, map.player_x);
    ft_path_free_and_error(&map);
    


    return (0);
}