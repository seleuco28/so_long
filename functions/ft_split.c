/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:10:19 by alvelazq          #+#    #+#             */
/*   Updated: 2023/08/01 17:13:52 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//este es el split que quiero, el mio de la libft da leaks

static	char	**ft_error_split(char **tab) //indagar/comentar en el split (y ver si libera el puntero del puntero)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

int	word_length(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char	**function_double_pointer(char const *s, char c, char **result, int words_count)
{
	int	i;
	int	j;
	int	w_len;

	while (*s == c)
		s++;
	i = -1;
	while (++i < words_count)
	{
		while (*s == c)
			s++;
		j = 0;
		w_len = word_length(s, c);
		result[i] = (char *)malloc(sizeof(char) * (w_len + 1));
		if (!(result[i]))
			return (ft_error_split(result));
		while (j < w_len)
		{
			result[i][j] = *s;
			s++;
			j++;
		}
		result[i][j] = '\0';
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		wcount;

	if (!s)
		return (NULL);
	wcount = word_count(s, c);
	result = (char **)malloc(sizeof(char *) * (wcount + 1));
	if (!(result))
		return (ft_error_split(result));
	result = function_double_pointer(s, c, result, wcount);
	result[wcount] = NULL;
	return (result);
}
/*
int		main(void)
{
	int i = 0;
	char **tab;

	tab = ft_split("      split       this for   me  !       ", ' ');
	while (i < 6)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}
*/