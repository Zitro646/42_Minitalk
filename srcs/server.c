/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:19:24 by root              #+#    #+#             */
/*   Updated: 2022/01/26 15:32:01 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_server	*g_srv_data;

void	server_reset(void)
{
	int	i;

	i = 0;
	g_srv_data->client_pid = -1;
	g_srv_data->msg_len = -1;
	g_srv_data->counter = 0;
	g_srv_data->byte = 0;
}

void	byte_reset(void)
{
	g_srv_data->counter = 0;
	g_srv_data->byte = 0;
}

void	control_binary(int signum)
{
	if (signum == SIGUSR1)
	{
		g_srv_data->byte += (1 << g_srv_data->counter);
	}
	g_srv_data->counter++;
	if (signum == SIGUSR1 && g_srv_data->client_pid != -1)
		kill(g_srv_data->client_pid, SIGUSR1);
	else if (signum == SIGUSR2 && g_srv_data->client_pid != -1)
		kill(g_srv_data->client_pid, SIGUSR2);
}

void	my_handler(int signum)
{
	control_binary(signum);
	if (g_srv_data->client_pid == -1 && g_srv_data->counter == 32)
	{
		g_srv_data->client_pid = g_srv_data->byte;
		byte_reset();
	}
	else if (g_srv_data->msg_len == -1 && g_srv_data->counter == 32)
	{
		g_srv_data->msg_len = g_srv_data->byte - 1;
		byte_reset();
	}
	else if (g_srv_data->msg_len != -1 && g_srv_data->counter == 8)
	{
		write(1, &g_srv_data->byte, 1);
		if (g_srv_data->msg_len == 0)
		{
			kill(g_srv_data->client_pid, SIGUSR1);
			server_reset();
		}
		else
		{
			g_srv_data->msg_len--;
			byte_reset();
		}
	}
}

int	main(void)
{
	g_srv_data = ft_calloc(sizeof(t_server), 1);
	g_srv_data->pid = getpid();
	g_srv_data->msg_len = -1;
	g_srv_data->client_pid = -1;
	g_srv_data->counter = 0;
	g_srv_data->byte = 0;
	ft_printf("Server PID  : %i\n", g_srv_data->pid);
	signal(SIGUSR1, my_handler);
	signal(SIGUSR2, my_handler);
	while (1)
	{
		sleep(1);
	}
	return (0);
}
