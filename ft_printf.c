/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:11:05 by sael-kha          #+#    #+#             */
/*   Updated: 2025/02/15 11:17:56 by sael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(const char *s, int i, va_list args)
{
	if (s[i] == 's')
		return (prints(va_arg(args, char *)));
	if (s[i] == 'c')
		return (printc(va_arg(args, int)));
	if (s[i] == 'p')
		return (printp(va_arg(args, void *)));
	if (s[i] == 'i' || s[i] == 'd')
		return (printid(va_arg(args, int)));
	if (s[i] == 'u')
		return (printu(va_arg(args, unsigned int)));
	if (s[i] == 'x' || s[i] == 'X')
		return (printx(va_arg(args, unsigned int), s[i]));
	if (s[i] == '%')
		return (write(1, "%", 1));
	return (0);
}

static int	is_one_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	if ((write(1, "", 0) == -1))
		return (-1);
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			if (is_one_set(s[i + 1], "cspdiuxX%"))
			{
				i++;
				count += handle_format(s, i, args);
			}
		}
		else if (s[i] != '%')
			count += write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
