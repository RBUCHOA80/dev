/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruchoa <ruchoa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 22:39:34 by ruchoa            #+#    #+#             */
/*   Updated: 2023/08/15 23:21:38 by ruchoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib.h"

int	ft_prod(int nbr1, int nbr2)
{
	int ret;

	ret = 0;
	ret = nbr1 * nbr2;
	return (ret);
}