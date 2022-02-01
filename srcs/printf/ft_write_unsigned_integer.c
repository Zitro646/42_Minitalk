/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_unsigned_integer.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:29:42 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/17 13:45:15 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_unsigned_integer(unsigned int number)
{	
	int	cont;

	cont = 1;
	if (number > 2147483647)
	{
		ft_putnbr((int)(number / 10));
		ft_putnbr((int)(number % 10));
	}
	else
		ft_putnbr((int)number);
	while (number / 10 != 0)
	{
		number /= 10;
		cont++;
	}
	return (cont);
}

/*
	// int --> 2147483647
	// uns --> 4294967295

	//gcc -Wall -Werror -Wextra ft_write_unsigned_integer.c ft_putnbr.c && ./a.out

int main(void)
{
	int a;
	a = ft_write_unsigned_integer(294967295);
	printf("\n Tamaño --> %i",a);
}
*/
