/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:44:16 by alvelazq          #+#    #+#             */
/*   Updated: 2023/08/18 14:12:40 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int key_hook(int keycode, t_game *map)
{
    /*if (keycode == M_UP || keycode == A_UP)
        move_up(); //hacer estas funciones, lo que se trata es
    else if (keycode == M_DOWN || keycode == A_DOWN)
        move_down();
    else if (keycode == M_RIGHT || keycode == A_RIGHT)
        move_right();
    else if (keycode == M_LEFT || keycode == A_LEFT)
        move_left();*/
    if (keycode == 53)
        ft_exit_game(map);
    return(0);
}