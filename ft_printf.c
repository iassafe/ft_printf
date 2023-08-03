/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:36:06 by iassafe           #+#    #+#             */
/*   Updated: 2022/11/28 11:24:48 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(va_list arg, char c)
{
	int	l;

	l = 0;
	if (c == 'c')
		l += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		l += ft_putstr(va_arg(arg, char *));
	else if (c == '%')
		l += ft_putchar('%');
	else if (c == 'd' || c == 'i')
		l += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		l += ft_putnbr_unsigned(va_arg(arg, unsigned int));
	else if (c == 'x')
		l += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		l += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
	{
		l += ft_putstr("0x");
		l += ft_putnbr_base(va_arg(arg, unsigned long), "0123456789abcdef");
	}
	else if (c != '\0')
		l += ft_putchar(c);
	return (l);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_check(args, str[i]);
		}
		else
			len += ft_putchar(str[i]);
		if (str[i] == '\0')
			break ;
		i++;
	}
	va_end(args);
	return (len);
}
