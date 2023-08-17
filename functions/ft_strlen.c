/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:36:17 by alvelazq          #+#    #+#             */
/*   Updated: 2023/08/01 14:16:26 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t  ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
        i++;
    return(i);
}
/*
int main(void)
{
    char *str;
    str = "abc";
    printf("%zu\n", ft_strlen(str));
    printf("%zu\n", strlen(str));
    return(0);
}
*/