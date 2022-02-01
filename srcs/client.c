/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:36:21 by root              #+#    #+#             */
/*   Updated: 2022/01/26 15:19:47 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	my_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("1");
	if (signum == SIGUSR2)
		ft_printf("0");
}

void	send_message(int pid, char *msg)
{
	int		i;
	int		iter_bit;

	i = 0;
	if (ft_strlen(msg) != 0)
	{
		while (msg[i])
		{
			iter_bit = 0;
			while (iter_bit < 8)
			{
				if (msg[i] & (1 << iter_bit))
				{
					kill(pid, SIGUSR1);
				}
				else
				{
					kill(pid, SIGUSR2);
				}
				iter_bit++;
				usleep(100);
			}
			i++;
		}
	}
}

void	send_integer(int pid_server, int nbr)
{
	int		iter_bit;
	int		prueba;

	if (pid_server >= 0)
	{
		prueba = 0;
		iter_bit = 0;
		while (iter_bit < 32)
		{
			if (nbr & (1 << iter_bit))
			{
				prueba += (nbr & (1 << iter_bit));
				kill(pid_server, SIGUSR1);
			}
			else
				kill(pid_server, SIGUSR2);
			iter_bit++;
			usleep(100);
		}
	}
}

int	main(int argc, char **argv)
{
	int		pid_client;
	int		pid_server;

	signal(SIGUSR1, my_handler);
	signal(SIGUSR2, my_handler);
	if (argc == 3)
	{
		if (ft_strlen(argv[2]) == 0)
		{
			ft_printf("El mensaje esta vacio");
			return (0);
		}
		pid_client = getpid();
		pid_server = ft_atoi(argv[1]);
		send_integer(pid_server, pid_client);
		send_integer(pid_server, ft_strlen(argv[2]));
		send_message(pid_server, argv[2]);
	}
	else
		ft_printf("Los datos no se han introducido correctamente\n");
	return (0);
}
