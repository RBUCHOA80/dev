/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_schemes_interpolated.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruchoa <ruchoa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:43:14 by ruchoa            #+#    #+#             */
/*   Updated: 2023/02/27 19:02:48 by ruchoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

/* interpolate:
*	Interpolates between two hex colors. Each color channel must be
*	calculated separately according to the formula:
*		(endValue - startValue) * stepNumber / lastStepNumber + startValue
*	The fractional component (stepNumber / lastStepNumber) must be provided
*	as fraction parameter of this function.
*	Note: rgb[3] : [0] = red, [1] = green, [2] = blue
*/
static int	interpolate(int startcolor, int endcolor, double fraction)
{
	int	start_rgb[3];
	int	end_rgb[3];

	start_rgb[0] = ((startcolor >> 16) & 0xFF);
	start_rgb[1] = ((startcolor >> 8) & 0xFF);
	start_rgb[2] = ((startcolor >> 0) & 0xFF);
	end_rgb[0] = ((endcolor >> 16) & 0xFF);
	end_rgb[1] = ((endcolor >> 8) & 0xFF);
	end_rgb[2] = ((endcolor >> 0) & 0xFF);
	start_rgb[0] = (end_rgb[0] - start_rgb[0]) * fraction + start_rgb[0];
	start_rgb[1] = (end_rgb[1] - start_rgb[1]) * fraction + start_rgb[1];
	start_rgb[2] = (end_rgb[2] - start_rgb[2]) * fraction + start_rgb[2];
	return (0xFF << 24 | start_rgb[0] << 16 | start_rgb[1] << 8 | start_rgb[2]);
}

/* set_color_mono:
*	Sets a monochromatic color scheme. Colors range from
*	black to the provided color, to white near the fractal
*	border.
*/
void	set_color_mono(t_fractol *exec, int color)
{
	int		i;
	int		j;
	double	fraction;
	int		color1;
	int		color2;

	color1 = 0x000000;
	color2 = color;
	i = 0;
	while (i < MAX_ITERATIONS)
	{
		j = 0;
		while (j < MAX_ITERATIONS / 2)
		{
			fraction = (double)j / (MAX_ITERATIONS / 2);
			exec->palette[i + j] = interpolate(color1, color2, fraction);
			j++;
		}
		color1 = color2;
		color2 = 0xFFFFFF;
		i += j;
	}
	exec->palette[MAX_ITERATIONS -1] = 0;
}

/* set_color_multiple:
*	Sets a multicolor color scheme. Colors range from the
*	first color provided in the array to the last. The colors are
*	interpolated for a smooth transition between each. It is possible
*	to provide more than 4 colors by casting a larger array and specifying
*	how many colors are included.
*/
void	set_color_multiple(t_fractol *exec, int colors[4], int n)
{
	int		i;
	int		j;
	int		x;
	double	fraction;

	i = 0;
	x = 0;
	while (i < MAX_ITERATIONS)
	{
		j = 0;
		while ((i + j) < MAX_ITERATIONS && j < (MAX_ITERATIONS / (n - 1)))
		{
			fraction = (double)j / (MAX_ITERATIONS / (n - 1));
			exec->palette[i + j] = \
				interpolate(colors[x], colors[x + 1], fraction);
			j++;
		}
		x++;
		i += j;
	}
	exec->palette[MAX_ITERATIONS - 1] = 0;
}