/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruchoa <ruchoa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:21:45 by ruchoa            #+#    #+#             */
/*   Updated: 2023/10/28 22:35:24 by ruchoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_history(char *line)
{
	if (*line != '\0')
		add_history(line);
	return (EXIT_SUCCESS);
}