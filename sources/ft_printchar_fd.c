/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glopez-c <glopez-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:53:17 by glopez-c          #+#    #+#             */
/*   Updated: 2024/10/03 16:34:51 by glopez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Prints the character c to the file descriptor fd.
 * 		- c: the character to print.
 * 		- fd: the file descriptor to print to.
 * Returns the number of characters printed (1) or -1 if an error occurs.
 */

int	ft_printchar_fd(char c, int fd)
{
	int	x;

	x = write(fd, &c, 1);
	return (x);
}
