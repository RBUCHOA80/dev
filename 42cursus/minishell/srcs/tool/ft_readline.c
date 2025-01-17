/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruchoa <ruchoa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 23:31:32 by ruchoa            #+#    #+#             */
/*   Updated: 2023/11/25 22:17:12 by ruchoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_prompt(char *user)
{
	char	buf[FILENAME_MAX];
	char	*prompt;

	prompt = ft_strjoin(GREEN, user);
	prompt = ft_strjoin(prompt, "@minishell");
	prompt = ft_strjoin(prompt, NONE);
	prompt = ft_strjoin(prompt, ":");
	prompt = ft_strjoin(prompt, RED);
	prompt = ft_strjoin(prompt, getcwd(buf, FILENAME_MAX));
	prompt = ft_strjoin(prompt, NONE);
	prompt = ft_strjoin(prompt, "$ ");
	return (prompt);
}

int	ft_readline(t_minishell *data, char *user)
{
	char	*line;

	line = readline(ft_prompt(user));
	if (ft_tokenize(data, line) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_history(line);
	ft_pipe_init(data);
	data->child_pid = ft_calloc(data->pipe_count + 1, sizeof(pid_t));
	return (EXIT_SUCCESS);
}
