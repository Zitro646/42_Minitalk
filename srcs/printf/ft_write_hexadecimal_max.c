/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hexadecimal_max.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:10:13 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/17 13:45:59 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_hexadecimal_max(int num)
{
	unsigned int	temp;
	unsigned int	aux;
	unsigned int	cont;
	unsigned int	auxnum;

	cont = 1;
	auxnum = (unsigned int)num;
	temp = auxnum % 16;
	aux = auxnum / 16;
	if (aux != 0)
	{
		cont += ft_write_hexadecimal_max(aux);
	}
	if (temp < 10)
		ft_write_char ((char)(temp + 48));
	else
		ft_write_char ((char)(temp + 55));
	return (cont);
}
