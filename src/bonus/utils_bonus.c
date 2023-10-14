/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:06:22 by alvelazq          #+#    #+#             */
/*   Updated: 2023/10/14 12:33:01 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	ft_check_args(int ac, char *av)
{
	int	len;

	if (ac != 2)
	{
		ft_putstr("Invalid number of arguments\n");
		exit(0);
	}
	else
	{
		len = ft_strlen(av);
		if (ft_strncmp(av + (len - 4), ".ber", 4))
		{
			ft_putstr("Invalid archive type, you need a '.ber'\n");
			exit(0);
		}
	}
}

void	draw_numbers(t_game *map)
{
	char	*text;

	text = ft_itoa(map->movements);
	mlx_string_put(map->mlx, map->win, 32, 32, WHITE, text);
	free(text);
}

int	ft_exit_game(t_game *map)
{
	mlx_clear_window(map->mlx, map->win);
	mlx_destroy_window(map->mlx, map->win);
	ft_free_map_principal(map);
	exit(0);
}
