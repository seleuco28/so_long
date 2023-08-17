/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:06:22 by alvelazq          #+#    #+#             */
/*   Updated: 2023/08/01 14:55:39 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int ft_error_msg(char *message) //solo mensaje de error, para liberar habria otra funcion
{
    printf("%s", message);

    exit(0); //no se si poner en exit(EXIT_FAILURE)
}

void ft_check_args(int ac, char *av)
{
    int len;

    if (ac != 2)
        ft_error_msg("Invalid number of arguments\n");
    else
    {
        len = ft_strlen(av);
        if (ft_strncmp(av + (len - 4), ".ber", 4)) //atencion esta comparacijon la puedo usar con ft_strcmp¿?¿?
            ft_error_msg("Invalid archive type, you need a '.ber'\n");
    }
    //printf("FUNCIONA SIGA!!!\n");
}