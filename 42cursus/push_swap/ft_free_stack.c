/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruchoa <ruchoa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:48:25 by ruchoa            #+#    #+#             */
/*   Updated: 2022/11/21 22:07:14 by ruchoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_free_stack(t_stack *stack)
{
	int	count;

	if (!stack)
		return ;
	count = ft_stacklen(stack);
	while (count--)
	{
		ft_printf("freeing Node[%i]\n", count);
	}
	free(stack);
}
