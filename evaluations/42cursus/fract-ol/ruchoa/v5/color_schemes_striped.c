/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_schemes_striped.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruchoa <ruchoa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:43:32 by ruchoa            #+#    #+#             */
/*   Updated: 2023/02/16 21:22:39 by ruchoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

/* fill_color:
*	Sets a color for particular stripes intervals.
*	If stripes = 2, the coloring will skip a palette iteration,
*	if stripes = 3, the coloring will skip 2 palette iterations, and so on.
*/
static void	fill_color_stripe(t_fractol *exec, int color, int stripe)
{
	int	i;

	i = 0;
	while (i < MAX_ITERATIONS)
	{
		exec->palette[i] = color;
		i += stripe;
	}
}

/* get_percent_color:
*	Calculates a color that is a certain percentage away
*	from the provided color. Each color channel must be calculated
*	separately. Intended to find somewhat complimentary colors.
*	(For true complimentary colors picked from the color wheel,
*	this function would need to be radically modified to use
*	HSL colors rather than RGB...)
*	Note: rgb[3] : rgb[0] = red, rgb[1] = green, rgb[2] = blue
*/
int	get_percent_color(int color, double percent)
{
	int		rgb[3];
	int		trgb[3];
	double	percentage;

	rgb[0] = (color >> 16) & 0xFF;
	rgb[1] = (color >> 8) & 0xFF;
	rgb[2] = (color >> 0) & 0xFF;
	percentage = (percent / 100) * 256;
	trgb[0] = (rgb[0] + percentage) - 256;
	trgb[1] = (rgb[1] + percentage) - 256;
	trgb[2] = (rgb[2] + percentage) - 256;
	return (0xFF << 24 | trgb[0] << 16 | trgb[1] << 8 | trgb[2]);
}

/* set_color_zebra:
*	Sets a zebra-striped color scheme. Colors alternate between
*	the given color and a complimentary color 50% away from the
*	first.
*/
void	set_color_zebra(t_fractol *exec, int color)
{
	int	color2;

	color2 = get_percent_color(color, 50);
	fill_color_stripe(exec, color, 1);
	fill_color_stripe(exec, color2, 2);
	exec->palette[MAX_ITERATIONS - 1] = 0;
}

/* set_color_triad:
*	Sets a striped color scheme. Colors alternate between
*	three colors: the given color, a color 33% away from the first
*	and a color 66% away from the first.
*/
void	set_color_triad(t_fractol *exec, int color)
{
	int		triad[2];

	triad[0] = get_percent_color(color, 33);
	triad[1] = get_percent_color(color, 66);
	fill_color_stripe(exec, color, 1);
	fill_color_stripe(exec, triad[0], 2);
	fill_color_stripe(exec, triad[1], 3);
	exec->palette[MAX_ITERATIONS - 1] = 0;
}

/* set_color_tetra:
*	Sets a striped color scheme. Colors alternate between
*	four colors: the given color, a color 25% away from it,
*	a color 50% away from the first, and a color 75% away from
*	the first.
*/
void	set_color_tetra(t_fractol *exec, int color)
{
	int	tetra[3];

	tetra[0] = get_percent_color(color, 25);
	tetra[1] = get_percent_color(color, 50);
	tetra[2] = get_percent_color(color, 75);
	fill_color_stripe(exec, color, 1);
	fill_color_stripe(exec, tetra[0], 2);
	fill_color_stripe(exec, tetra[1], 3);
	fill_color_stripe(exec, tetra[2], 4);
	exec->palette[MAX_ITERATIONS - 1] = 0;
}
