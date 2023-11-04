/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruchoa <ruchoa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 23:37:00 by ruchoa            #+#    #+#             */
/*   Updated: 2023/10/29 21:24:34 by ruchoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_env(t_minishell *data)
{
	t_list	*temp;

	data->token = data->token->next;
	temp = data->env;
	while (temp && temp->content)
	{
		ft_fprintf(data->fdout, "%s\n", (char *)temp->content);
		temp = temp->next;
	}
	return (EXIT_SUCCESS);
}