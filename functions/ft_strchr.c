/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:37:34 by alvelazq          #+#    #+#             */
/*   Updated: 2023/08/01 17:38:05 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (0);
}

/*
int main(void)
{
	char str[] = "tripouillete hola buenas tardes";
	char str1[] = "tripouillete hola buenas tardes";

	printf("%s\n", ft_strchr(str, 'a'));
	printf("%s\n", strchr(str1, 'a'));
	return (0);
}
*/