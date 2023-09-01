/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:10:02 by alvarovelaz       #+#    #+#             */
/*   Updated: 2022/05/10 10:49:13 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_len(int nbr)
{
	int	leng;

	if (nbr <= 0)
		leng = 1;
	else
		leng = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		leng++;
	}
	return (leng);
}

int	ft_putnbr(int n)
{
	int	len;

	len = ft_len(n);
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		if (n < 10)
			ft_putchar(n + '0');
		else
		{
			ft_putnbr(n / 10);
			ft_putchar(n % 10 + '0');
		}
	}
	return (len);
}
