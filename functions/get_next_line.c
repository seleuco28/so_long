/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 09:45:21 by alvelazq          #+#    #+#             */
/*   Updated: 2023/08/01 17:43:01 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//CAMBIADO PARA QUE LAS FUNCIONES ESTEN EN INGLES

char	*ft_print_line(char *str)
{
	int		i;
	char	*linea;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	linea = (char *)malloc(sizeof(char) * (i + 2));
	if (!linea)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		linea[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		linea[i] = str[i];
		i++;
	}
	linea[i] = '\0';
	return (linea);
}

/*
int main(void) // Te pinta la linea hasta el \n (INCLUIDO)
{
    char *str;
    str = "12345\n678";
    printf("%s", ft_print_line(str));
    
    return(0);
}
*/

char	*ft_new_line(char *str)
{
	int		x;
	int		y;
	char	*linea;

	x = 0;
	y = 0;
	while (str[x] && str[x] != '\n')
		x++;
	if (!str[x])
	{
		free(str);
		return (NULL);
	}
	linea = (char *)malloc(sizeof(char) * (ft_strlen(str) - x));
	if (!linea)
		return (NULL);
	x++;
	while (str[x])
		linea[y++] = str[x++];
	linea[y] = '\0';
	free(str);
	return (linea);
}

/*
int main(void) // comentar el free(str) de la funcion para compilar
{
    char *str;
    str = "1234\n5678\n9";
    printf("%s", ft_new_line(str));
	// asi vamos saltando de linea en linea hasta el final
	//str = ft_new_line(str);
	//printf("%s", ft_new_line(str));
	system("leaks a.out");
    return (0);
}
*/

char	*ft_read_print(int fd, char *str)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(str, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

/*
int main(void)
{
	int fd;
	//char *str;
	char *str1;

	//str = "123\n456\n789\n";
	str1 = "\n";
	fd = 1;

	printf("%s", ft_read_print(fd ,str1));
	
	return (0);
}
*/

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read_print(fd, str);
	if (!str)
		return (NULL);
	line = ft_print_line(str);
	str = ft_new_line(str);
	return (line);
}
