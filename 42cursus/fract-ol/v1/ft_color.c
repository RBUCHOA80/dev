/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruchoa <ruchoa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:57:34 by ruchoa            #+#    #+#             */
/*   Updated: 2023/07/29 20:15:58 by ruchoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

int	ft_interpolate(int startcolor, int endcolor, double fraction)
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

void	ft_change_color(t_data *f, int color)
{
	int		i;
	int		j;
	double	fraction;
	int		color1;
	int		color2;

	color1 = 0;
	color2 = color;
	i = 0;
	while (i < MAX_ITERATIONS)
	{
		j = 0;
		while (j < MAX_ITERATIONS / 2)
		{
			fraction = (double)j / (MAX_ITERATIONS / 2);
			f->color_table[i + j] = ft_interpolate(color1, color2, fraction);
			j++;
		}
		color1 = color2;
		color2 = 0x00613c;
		i += j;
	}
	f->color_table[MAX_ITERATIONS -1] = 0;
}

void	ft_set_color(t_data *exec)
{
	if (exec->color == 0)
	{
		ft_change_color(exec, 0x870a28);
		exec->color = 1;
	}
	else
	{
		ft_change_color(exec, 0xFFFFFF);
		exec->color = 0;
	}
}