/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruchoa <ruchoa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:39:47 by ruchoa            #+#    #+#             */
/*   Updated: 2023/02/27 19:45:45 by ruchoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

double	ft_abs(double c)
{
	double	ret;

	if (c < 0)
		ret = -c;
	else
		ret = c;
	return (ret);
}
