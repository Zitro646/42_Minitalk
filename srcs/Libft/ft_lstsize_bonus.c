/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:09:21 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/17 13:43:13 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	if (lst != 0)
	{
		count = 1;
		while (lst->next != 0)
		{	
			lst = lst->next;
			count++;
		}
		return (count);
	}
	return (0);
}
