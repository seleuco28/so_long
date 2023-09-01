/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:06:22 by alvelazq          #+#    #+#             */
/*   Updated: 2023/09/01 11:07:23 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_error_msg(char *message)
{
	printf("%s", message);
	exit(0);
}

void	ft_check_args(int ac, char *av)
{
	int	len;

	if (ac != 2)
		ft_error_msg("Invalid number of arguments\n");
	else
	{
		len = ft_strlen(av);
		if (ft_strncmp(av + (len - 4), ".ber", 4))
			ft_error_msg("Invalid archive type, you need a '.ber'\n");
	}
}
