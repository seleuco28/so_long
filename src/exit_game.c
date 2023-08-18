/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:35:15 by alvelazq          #+#    #+#             */
/*   Updated: 2023/08/18 13:39:28 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int ft_exit_game(t_game *map)
{
    mlx_clear_window(map->mlx, map->win);
    ft_free_map_principal(map);
    mlx_destroy_window(map->mlx, map->win);
    exit(0);
}