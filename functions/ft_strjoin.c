/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:38:23 by alvelazq          #+#    #+#             */
/*   Updated: 2023/08/01 17:38:37 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	x;
	unsigned int	y;
	char			*str;

	x = -1;
	y = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[++x])
		str[x] = s1[x];
	while (s2[y])
		str[x++] = s2[y++];
	str[x] = '\0';
	free(s1);
	return (str);
}
/*
int main(void)
{
	char str1[] = "hola buenas ";
	char str2[] = "como estamos?";
	
	printf("%s\n", ft_strjoin(str1 , str2));
	return (0);
}
*/