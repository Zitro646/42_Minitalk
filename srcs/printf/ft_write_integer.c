/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:26:28 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/11/23 09:49:38 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_integer(int number)
{
	int	cont;

	if (number < 0)
		cont = 2;
	else
		cont = 1;
	ft_putnbr(number);
	while (number / 10 != 0)
	{
		number /= 10;
		cont++;
	}
	return (cont);
}

/*
int main(void)
{
	int tamaño = ft_write_integer(-1234567);
	printf ("Tamaño --> %i ",tamaño);
}
*/
// gcc -Wall -Werror -Wextra ft_write_integer.c ft_putnbr.c &&	./a.out