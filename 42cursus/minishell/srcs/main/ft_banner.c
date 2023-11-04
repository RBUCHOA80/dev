/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_banner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruchoa <ruchoa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:29:38 by ruchoa            #+#    #+#             */
/*   Updated: 2023/11/01 19:09:41 by ruchoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_banner(void)
{
	ft_fprintf(1, "            _         _       _            _  _ \n");
	ft_fprintf(1, "           (_)       (_)     | |          | || |\n");
	ft_fprintf(1, " _ __ ___   _  _ __   _  ___ | |__    ___ | || |\n");
	ft_fprintf(1, "| '_ ` _ \\ | || '_ \\ | |/ __|| '_ \\  / _ \\| || |\n");
	ft_fprintf(1, "| | | | | || || | | || |\\__ \\| | | ||  __/| || |\n");
	ft_fprintf(1, "|_| |_| |_||_||_| |_||_||___/|_| |_| \\___||_||_|\n");
	ft_fprintf(1, "\n");
	return (EXIT_SUCCESS);
}