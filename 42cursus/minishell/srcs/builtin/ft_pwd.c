/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruchoa <ruchoa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:56:19 by ruchoa            #+#    #+#             */
/*   Updated: 2023/10/29 22:01:52 by ruchoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_pwd(t_minishell *data)
{
	char	buf[FILENAME_MAX];

	data->token = data->token->next;
	if (getcwd(buf, FILENAME_MAX))
	{
		ft_fprintf(data->fdout, "%s\n", buf);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}