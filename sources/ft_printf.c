/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:03:21 by glopez-c          #+#    #+#             */
/*   Updated: 2024/10/03 16:34:06 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Checks if the character c is a format specifier.
 * 		- c: the character to check.
 * Returns 1 if c is a valid format specifier, 0 otherwise.
 */

static int	ft_isformat(char c)
{
	size_t	i;
	char	*s;

	s = "cs%diupxX";
	i = -1;
	while (s[++i])
		if (c == s[i])
			return (i + 1);
	return (0);
}

/* Calls the appropriate function for each format specifier,
 * using va_arg to extract the arguments from the va_list.
 * 		- args: the va_list containing the arguments.
 * 		- c: the format specifier.
 * Returns the number of characters printed, or -1 if an error occurs.
 */

static int	ft_printaux(va_list args, char c)
{
	int		res;

	if (c == 'c')
		res = ft_printchar_fd(va_arg(args, int), 1);
	if (c == '%')
		res = ft_printchar_fd('%', 1);
	if (c == 's')
		res = ft_printstr_fd(va_arg(args, char *), 1);
	if (c == 'd' || c == 'i')
		res = ft_printnbr_fd(va_arg(args, int), 1, 0);
	if (c == 'u')
		res = ft_printnbr_fd(va_arg(args, unsigned int), 1, 0);
	return (res);
}

static int	ft_printhex(va_list args, char c)
{
	int		res;
	long	ptr;

	if (c == 'p')
	{
		ptr = va_arg(args, unsigned long);
		if (!ptr)
		{
			res = ft_printstr_fd("0x0", 1);
			return (res);
		}
		res = ft_printstr_fd("0x", 1);
		if (res != -1)
			res += ft_printunbr_base_fd(ptr, "0123456789abcdef", 1);
	}
	if (c == 'x')
		res = ft_printunbr_base_fd(va_arg(args, unsigned int),
				"0123456789abcdef", 1);
	if (c == 'X')
		res = ft_printunbr_base_fd(va_arg(args, unsigned int),
				"0123456789ABCDEF", 1);
	return (res);
}

/* Initializes the va_list, then iterates through the string s 
 * printing each character to the standard output, or
 * calling the appropriate function for each format specifier.
 * 		- s: the string to print.
 * 		- ...: the arguments to be printed.
 * Returns the number of characters printed, or -1 if an error occurs.
 */

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		len;
	int		j;
	int		i;

	if (!s)
		return (0);
	va_start(args, s);
	len = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%' && ft_isformat(s[i + 1]) >= 7)
			j = ft_printhex(args, s[++i]);
		else if (s[i] == '%' && ft_isformat(s[i + 1]) >= 1)
			j = ft_printaux(args, s[++i]);
		else
			j = ft_printchar_fd(s[i], 1);
		if (j == -1)
			return (j);
		len += j;
	}
	va_end(args);
	return (len);
}
