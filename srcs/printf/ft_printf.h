/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:45:43 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/17 13:45:44 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

void	ft_putnbr(int nb);

int		ft_printf(const char *c, ...);
int		ft_write_char(int c);
int		ft_write_string(const char *c);
int		ft_write_pointer(const void *c);
int		ft_write_decimal(int number);
int		ft_write_integer(int number);
int		ft_write_unsigned_integer(unsigned int number);
int		ft_write_hexadecimal_min(int num);
int		ft_write_hexadecimal_max(int num);
#endif