/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:38:43 by alvelazq          #+#    #+#             */
/*   Updated: 2023/08/01 13:40:17 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (i < (n - 1)))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
int main(void)
{
    char str1[] = "test\200";
    char str2[] = "test\0";

    printf("%d\n", strncmp(str1, str2, 6));
    printf("%d\n", ft_strncmp(str1, str2, 6));


    return(0);    
}
*/