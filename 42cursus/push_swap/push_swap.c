/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruchoa <ruchoa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:35:50 by ruchoa            #+#    #+#             */
/*   Updated: 2023/01/02 21:46:43 by ruchoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_inorder(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack && stack->next)
	{
		if ((*(int *)stack->next->content - *(int *)stack->content) != 1)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_search_index(t_list *stack, int mid)
{
	int	dist;
	int	len;
	static int	n;

	n = ft_lstsize(stack) / 20;
	len = ft_lstsize(stack);
	dist = 0;
	while (stack && stack->next && *((int *)stack->content) <= (mid + n) && *((int *)stack->content) > (mid - n))
	{
		stack = stack->next;
		dist++;
	}
	if (dist > len / 2)
		return (-1 * (len - dist));
	else
		return (dist);
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	mid;
	int	dist;

	if (!(stack_a && stack_b))
		return ;
	mid = ft_lstsize(*stack_a) / 2;
	ft_printf_stacks(*stack_a, *stack_b);
	while ((*stack_a) && (*stack_a)->next && !ft_inorder(*stack_a))
	{
		if ((*((int *)(*stack_a)->content) - *((int *)(*stack_a)->next->content)) == 1)
			sa(stack_a);
		dist = ft_search_index(*stack_a, mid++);
		if (dist > 0)
			while (dist--)
				ra(stack_a);
		else if (dist < 0)
			while (dist++)
				rra(stack_a);
		if (!ft_inorder(*stack_a))
			pb(stack_a, stack_b);
		if ((*stack_b) && (*stack_b)->next && (*((int *)(*stack_b)->next->content) - *((int *)(*stack_b)->content)) == 1)
			sb(stack_b);
		ft_printf_stacks(*stack_a, *stack_b);
	}
	while ((*stack_b))
		pa(stack_b, stack_a);
	ft_printf_stacks(*stack_a, *stack_b);
}
