/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 08:53:26 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/17 13:44:48 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	argument_managment(int cont, const char *c, void *var);
static int	print_format(int cont, const char *c, va_list argument);

int	ft_printf(const char *c, ...)
{
	int		cont;
	int		retorno;
	va_list	argument;

	cont = 0;
	retorno = 0;
	va_start(argument, c);
	retorno = print_format(cont, c, argument);
	va_end(argument);
	return (retorno);
}

static int	print_format(int cont, const char *c, va_list argument)
{
	int	retorno;

	retorno = 0;
	while (c[cont] != 0)
	{
		if (c[cont] == '%')
		{
			if (c[cont + 1] == 'c' || c[cont + 1] == 's' || c[cont + 1] == 'p' \
			|| c[cont + 1] == 'd' || c[cont + 1] == 'i' || c[cont + 1] == 'u' \
			|| c[cont + 1] == 'x' || c[cont + 1] == 'X')
				retorno += argument_managment(cont, c, \
								va_arg(argument, void *));
			else
				retorno += argument_managment(cont, c, NULL);
			cont++;
		}	
		else
			retorno += ft_write_char(c[cont]);
		cont++;
	}
	return (retorno);
}

static int	argument_managment(int cont, const char *c, void *var)
{
	if (c[cont + 1] == 'c')
		return (ft_write_char ((int)var));
	else if (c[cont + 1] == 's')
		return (ft_write_string((char *)var));
	else if (c[cont + 1] == 'p')
		return (ft_write_pointer(var));
	else if (c[cont + 1] == 'd')
		return (ft_write_decimal((int)var));
	else if (c[cont + 1] == 'i')
		return (ft_write_integer((int)var));
	else if (c[cont + 1] == 'u')
		return (ft_write_unsigned_integer((unsigned int)var));
	else if (c[cont + 1] == 'x')
		return (ft_write_hexadecimal_min((int)var));
	else if (c[cont + 1] == 'X')
		return (ft_write_hexadecimal_max((int)var));
	else
		return (ft_write_char('%'));
}
