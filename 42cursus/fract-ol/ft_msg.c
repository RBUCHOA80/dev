/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruchoa <ruchoa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:38:49 by ruchoa            #+#    #+#             */
/*   Updated: 2023/08/02 21:04:00 by ruchoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	ft_msg(void)
{
	ft_printf("Incorrect fract-ol's set or number of parameters.\n");
	ft_printf("\tValid options:\n");
	ft_printf("\t\t./fractol m -> for Mandelbrot fract-ol Set\n");
	ft_printf("\t\t./fractol j -> for Julia fract-ol Preset\n");
	ft_printf("\t\t./fractol j x.x y.y -> for Julia fract-ol Set\n");
	exit(1);
}
