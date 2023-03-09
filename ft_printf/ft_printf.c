/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykostan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:49:30 by lykostan          #+#    #+#             */
/*   Updated: 2023/01/28 20:49:33 by lykostan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptnbrbs(unsigned int n, char *base, unsigned int num)
{
	int	count;

	count = 0;
	if (n > num - 1)
		count += ft_ptnbrbs(n / num, base, num);
	n = n % num;
	count++;
	write(1, &(base[n]), 1);
	return (count);
}

static int	pointer(uintptr_t n, char *base, unsigned int num)
{
	int	count;

	count = 0;
	if (n > num - 1)
		count += pointer(n / num, base, num);
	n = n % num;
	count++;
	write(1, &(base[n]), 1);
	return (count);
}

static void	check(int *count, char c, va_list args)
{
	if (c == 'd' || c == 'i')
		*count += ft_putnbr_pf(va_arg(args, int));
	else if (c == 's')
		*count += ft_putstr_pf(va_arg(args, char *));
	else if (c == 'c')
	{
		ft_putchar_pf(va_arg(args, int));
		(*count)++;
	}
	else if (c == 'u')
		*count += ft_ptnbrbs(va_arg(args, unsigned), "0123456789", 10);
	else if (c == 'x')
		*count += ft_ptnbrbs(va_arg(args, unsigned), "0123456789abcdef", 16);
	else if (c == 'X')
		*count += ft_ptnbrbs(va_arg(args, unsigned), "0123456789ABCDEF", 16);
	else if (c == 'p')
	{
		*count += ft_putstr_pf("0x");
		*count += pointer(va_arg(args, uintptr_t), "0123456789abcdef", 16);
	}
	else if (c == '%')
	{
		ft_putchar_pf('%');
		(*count)++;
	}
}

static int	f(const char *s, va_list	args, int i)
{
	int	count;

	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (!s[i + 1])
				return (count);
			while (s[i + 1] && ft_strchr_pf("\\cspdiuxX%\n\t\f\r\v\a\b\?\"",
					s[i + 1]) == -1)
				i++;
			if (ft_strchr_pf("\\\n\t\f\r\v\a\b\?\"", s[i + 1]) >= 0 && ++count)
				ft_putchar_pf(s[++i]);
			else if (ft_strchr_pf("cspdiuxX%", s[i + 1]) >= 0)
				check(&count, s[++i], args);
		}
		else
		{
			ft_putchar_pf(s[i]);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	va_start(args, s);
	count = f(s, args, i);
	va_end(args);
	return (count);
}
