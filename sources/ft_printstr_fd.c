/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:54:16 by glopez-c          #+#    #+#             */
/*   Updated: 2024/10/03 21:12:02 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Prints the string s to the file descriptor fd.
 * 		- s: the string to print.
 * 		- fd: the file descriptor to print to.
 * Returns the number of characters printed or -1 if an error occurs.
 */

int	ft_printstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
	{
		i = write(1, "(null)", 6);
		return (i);
	}
	i = -1;
	while (s[++i])
		if (write(fd, &s[i], 1) == -1)
			return (-1);
	return (i);
}
