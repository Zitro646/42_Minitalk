/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hexadecimal_min.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:13:40 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/17 13:46:08 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_hexadecimal_min(int num)
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
		cont += ft_write_hexadecimal_min(aux);
	}
	if (temp < 10)
		ft_write_char ((char)(temp + 48));
	else
		ft_write_char ((char)(temp + 87));
	return (cont);
}
