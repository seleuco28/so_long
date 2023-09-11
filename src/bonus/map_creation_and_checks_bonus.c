/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation_and_checks_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:10:23 by alvelazq          #+#    #+#             */
/*   Updated: 2023/09/11 12:07:49 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	ft_map_creation(char *av, t_game *map)
{
	int		map_fd;
	char	*temp_line;
	char	*array_1;

	map_fd = open(av, O_RDONLY);
	if (!map_fd || map_fd == -1)
	{
		ft_putstr("File descriptor not found");
		exit(0);
	}
	array_1 = ft_strdup("");
	while (1)
	{
		temp_line = get_next_line(map_fd);
		if (temp_line == NULL)
			break ;
		array_1 = ft_strjoin(array_1, temp_line);
		free(temp_line);
	}
	map->map = ft_split(array_1, '\n');
	free (array_1);
	close (map_fd);
}

int	ft_check_valid_chars(t_game *map)
{
	char	**read;
	int		x;
	int		y;

	read = map->map;
	y = 0;
	while (read[y])
	{
		x = 0;
		while (read[y][x])
		{
			if (read[y][x] != '0' && read[y][x] != '1' &&
				read[y][x] != 'C' && read[y][x] != 'P'
					&& read[y][x] != 'E' && read[y][x] != 'Q')
			{
				ft_putstr("Unexpected char type\n");
				exit(0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

void	ft_check_map_length(t_game *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	map->x_max = ft_strlen(map->map[x]);
	map->y_max = 0;
	while (map->map[y])
	{
		map->y_max++;
		y++;
	}
	x = 0;
	while (map->map[x])
	{
		if (map->x_max != ft_strlen(map->map[x]))
		{
			ft_putstr("The map is not rectangular\n");
			exit(0);
		}
		x++;
	}
}
