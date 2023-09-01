/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:06:22 by alvelazq          #+#    #+#             */
/*   Updated: 2023/09/01 15:11:28 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
