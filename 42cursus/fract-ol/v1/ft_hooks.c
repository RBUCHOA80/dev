/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruchoa <ruchoa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:27:14 by ruchoa            #+#    #+#             */
/*   Updated: 2023/07/29 10:33:44 by ruchoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

int	ft_hooks(t_data *exec)
{
	mlx_key_hook(exec->win, &ft_key_events, exec);
	mlx_mouse_hook(exec->win, &ft_mouse_events, exec);
	mlx_hook(exec->win, 17, 0, &ft_close, exec);
	return (EXIT_SUCCESS);
}