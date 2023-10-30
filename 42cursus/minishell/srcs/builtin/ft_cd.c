/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruchoa <ruchoa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 23:40:38 by ruchoa            #+#    #+#             */
/*   Updated: 2023/10/29 21:34:25 by ruchoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_has_space(char *cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
		if (cmd[i] < 14 || cmd[i] == 32)
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_cd(t_minishell *data)
{
	char	*cmd;

	data->token = data->token->next;
	cmd = ft_get_cmd(data);
	if (ft_has_space(cmd) == EXIT_FAILURE)
		ft_fprintf(data->fdout, "minishell: cd: too many arguments\n");
	else if ((ft_strcmp(cmd, "") == EXIT_SUCCESS) || \
			(ft_strcmp(cmd, "~") == EXIT_SUCCESS))
	{
		if (chdir(ft_expand(data, "$HOME")) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	else if (chdir(cmd) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		ft_fprintf(data->fdout, \
			"minishell: cd: %s: no such file or directory\n", cmd);
	return (EXIT_FAILURE);
}
