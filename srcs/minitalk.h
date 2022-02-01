/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:19:47 by root              #+#    #+#             */
/*   Updated: 2022/01/26 11:08:53 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "./Libft/libft.h"
# include "./printf/ft_printf.h"
# include <sys/types.h>
# include <signal.h>
# include <unistd.h>

typedef struct server
{
	int		pid;
	int		client_pid;
	int		msg_len;
	int		counter;
	int		byte;
}t_server;

char	*ft_tobinary(int nbr);
void	send_char(int pid, char *binary);
void	send_integer(int pid_server, int pid_client);

void	turn_into_char(char *str);
int		turn_into_integer(char *str);

#endif