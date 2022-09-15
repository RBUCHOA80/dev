/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruchoa <ruchoa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:46:58 by ruchoa            #+#    #+#             */
/*   Updated: 2022/09/14 23:41:34 by ruchoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printflist(t_stack *list)
{
	int	i;

	i = 0;
	while (1)
	{
		ft_printf("%p \t", &list[i]);
		ft_printf("Node[%i] \t", i);
		ft_printf("Content = %i \t", list[i].content);
		ft_printf("Next = %p\n", list[i].next);
		if (!list[i].next)
			break ;
		i++;
	}	
}
