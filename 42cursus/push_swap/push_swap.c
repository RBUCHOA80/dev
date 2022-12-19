/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruchoa <ruchoa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:35:50 by ruchoa            #+#    #+#             */
/*   Updated: 2022/12/18 22:07:08 by ruchoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	i;

	if (stack_a && stack_b)
	{
		i = 0;
		while (i < ft_lstsize(*stack_a))
		{
			if (ft_lstsize(*stack_a) > 1 && ft_lstsize(*stack_b) > 1)
			{
				if (ft_atoi((*stack_a)->content) > ft_atoi((*stack_a)->next->content) && ft_atoi((*stack_b)->content) < ft_atoi((*stack_b)->next->content))
					ss(stack_a, stack_b);
				else if (ft_atoi((*stack_a)->content) > ft_atoi(ft_lstlast((*stack_a))->content) && ft_atoi((*stack_b)->content) < ft_atoi(ft_lstlast(*stack_b)->content))
					rr(stack_a, stack_b);
				else if (ft_atoi((*stack_a)->content) > ft_atoi(ft_lstlast((*stack_a))->content) && ft_atoi((*stack_b)->content) < ft_atoi(ft_lstlast(*stack_b)->content))
					rrr(stack_a, stack_b);
			}
			if (ft_lstsize(*stack_a) > 1)
			{
				if (*((int *)(*stack_a)->content) > *((int *)(*stack_a)->next->content))
					sa(stack_a);
				else if (*((int *)(*stack_a)->content) > *(int *)(ft_lstlast((*stack_a))->content))
					ra(stack_a);
				else if (*((int *)(*stack_a)->content) > *(int *)(ft_lstlast((*stack_a))->content))
					rra(stack_a);
			}
			if (ft_lstsize(*stack_b) > 1)
			{
				if (*((int *)(*stack_b)->content) < *((int *)(*stack_b)->next->content))
				
					sb(stack_b);
				else if (*((int *)(*stack_b)->content) < *(int *)(ft_lstlast(*stack_b)->content))
					rb(stack_b);
				else if (*((int *)(*stack_b)->content) < *(int *)(ft_lstlast(*stack_b)->content))
					rrb(stack_b);
			}
			i++;
		}
		ft_printf_stacks((*stack_a), (*stack_b));
	}
	return ;
}
