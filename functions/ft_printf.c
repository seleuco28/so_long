/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvelazq <alvelazq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 09:38:07 by alvelazq          #+#    #+#             */
/*   Updated: 2023/09/01 12:10:20 by alvelazq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf_xX.c"
#include "ft_printf_u.c"
#include "ft_printf_p.c"
#include "ft_printf_s.c"
#include "ft_printf_di.c"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_formats(va_list *args, char const str)
{
	int	len_str;

	len_str = 0;
	if (str == 's')
		len_str += ft_putstr(va_arg(*args, char *));
	else if (str == 'c')
		len_str += ft_printchar(va_arg(*args, int));
	else if (str == 'd' || str == 'i')
		len_str += ft_putnbr(va_arg(*args, int));
	else if (str == 'p')
		len_str += ft_print_ptr(va_arg(*args, unsigned long long));
	else if (str == 'u')
		len_str += ft_print_unsigned(va_arg(*args, unsigned int));
	else if (str == 'x')
		len_str += ft_dec_a_hex_min(va_arg(*args, int));
	else if (str == 'X')
		len_str += ft_dec_a_hex(va_arg(*args, int));
	else if (str == '%')
		len_str += ft_printpercent();
	else
		len_str += ft_printchar(str);
	return (len_str);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		len_str;

	i = 0;
	len_str = 0;
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%')
			len_str += ft_formats(&args, str[++i]);
		else
			len_str += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (len_str);
}
