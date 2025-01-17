/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruchoa <ruchoa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:32:26 by ruchoa            #+#    #+#             */
/*   Updated: 2023/11/03 21:02:21 by ruchoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftfprintf.h"

int	ft_fprintf(int fd, const char *str, ...)
{
	int					index;
	va_list				var;
	int					ret;

	va_start(var, str);
	ret = 0;
	index = 0;
	while (str[index])
	{
		if (str[index] == '%')
			ret += ft_aux(str[index++ + 1], var, fd);
		else
			ret += write(fd, &str[index], 1);
		index++;
	}
	va_end(var);
	return (ret);
}

int	ft_aux(char str, va_list var, int fd)
{
	int	ret;

	ret = 0;
	if (str == 'c')
		ret = ft_character_output(var, fd);
	else if (str == 's')
		ret = ft_string_output(var, fd);
	else if (str == 'p')
		ret = ft_pointer_output(var, fd);
	else if (str == 'd')
		ret = ft_decimal_output(var, fd);
	else if (str == 'i')
		ret = ft_integer_output(var, fd);
	else if (str == 'u')
		ret = ft_unsigned_integer_output(var, fd);
	else if (str == 'x')
		ret = ft_hexadecimal_lower_output(var, fd);
	else if (str == 'X')
		ret = ft_hexadecimal_upper_output(var, fd);
	else if (str == '%')
		ret = write(fd, "%", 1);
	return (ret);
}
