/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruchoa <ruchoa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 09:57:43 by ruchoa            #+#    #+#             */
/*   Updated: 2023/07/04 23:21:50 by ruchoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_width(int size)
{
	int	increase;
	int	heigth;
	int	tier;

	increase = 1;
	heigth = 0;
	tier = 1;
	while (tier <= size)
	{
		increase += ((tier + 1) % 2);
		heigth += 3 + tier - 1 + increase;
		tier++;
	}
	return (heigth);
}

int	ft_offset(int col, int size, int row)
{
	while (col < ((((2 * ft_width(size)) - 1) / 2) - row))
	{
		write(1, " ", 1);
		col++;
	}
	return (col);
}

int	ft_fill(int col, int size, int row, int tier)
{
	write(1, "/", 1);
	while (col < (((2 * ft_width(size)) - 1) / 2) - 1 + row)
	{
		if (tier == size
			&& row + tier - ((tier + 1) % 2) >= ft_width(tier)
			&& col >= ((((2 * ft_width(size)) - 1) - 2) / 2)
			- ((tier - ((tier + 1) % 2)) / 2)
			&& col <= ((((2 * ft_width(size)) - 1) - 2) / 2)
			+ ((tier - ((tier + 1) % 2)) / 2))
			if (col == (((((2 * ft_width(size)) - 1) - 2) / 2)
					+ ((tier - ((tier + 1) % 2)) / 2) - 1)
				&& row + tier - ((tier + 1) % 2) == (ft_width(tier))
				+ ((tier - ((tier + 1) % 2)) / 2)
				&& size >= 5)
				write(1, "$", 1);
		else
			write(1, "|", 1);
		else
			write(1, "*", 1);
		col++;
	}
	write(1, "\\", 1);
	write(1, "\n", 1);
	return (col);
}

void	sastantua(int size)
{
	int	increase;
	int	tier;
	int	row;
	int	col;

	increase = 0;
	row = 0;
	tier = 0;
	while (tier <= size)
	{
		row = 0;
		while (row < ft_width(tier))
		{
			if (row > ft_width(tier - 1) + increase)
			{
				col = 0;
				col = ft_offset(col, size, row);
				col = ft_fill(col, size, row, tier);
			}
			row++;
		}
		increase += (tier % 2);
		tier++;
	}
}

int	main(int argc, char **argv)
{
	int	size;
	int	i;

	if (argc != 2)
	{
		write(1, "Wrong number of arguments.\n", 27);
		return (1);
	}
	size = 0;
	i = 0;
	while (argv[1][i])
	{
		size = size + argv[1][i] - 48;
		i++;
	}
	sastantua(size);
	return (0);
}
