/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruchoa <ruchoa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:35:50 by ruchoa            #+#    #+#             */
/*   Updated: 2023/01/08 10:45:53 by ruchoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

//v3.0

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a))
		pb(stack_a, stack_b);
	while (ft_lstsize(*stack_b))
		pa(stack_b, stack_a);
}
