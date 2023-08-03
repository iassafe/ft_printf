/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:05:22 by iassafe           #+#    #+#             */
/*   Updated: 2022/12/02 12:05:43 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	long	nb;
	int		len;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb *= (-1);
	}
	if (nb >= 10)
		len += ft_putnbr(nb / 10);
	len += ft_putchar(nb % 10 + '0');
	return (len);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	unsigned int	nb;
	int				len;

	nb = n;
	len = 0;
	if (nb >= 10)
	{
		len += ft_putnbr_unsigned(nb / 10);
		len += ft_putnbr_unsigned(nb % 10);
	}
	else
		len += ft_putchar(nb + '0');
	return (len);
}

int	ft_putnbr_base(unsigned long n, char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_putnbr_base(n / 16, base);
	len += ft_putchar(base[n % 16]);
	return (len);
}
