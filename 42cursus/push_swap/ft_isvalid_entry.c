/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid_entry.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruchoa <ruchoa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 07:31:48 by ruchoa            #+#    #+#             */
/*   Updated: 2023/03/04 21:25:07 by ruchoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isvalid_entry(char **strs)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (strs[++i])
	{
		str = ft_itoa(ft_atoi(strs[i]));
		if (ft_strncmp(strs[i], str, ft_strlen(strs[i])))
		{
			free(str);
			return (0);
		}
		free(str);
		j = i + 1;
		while (strs[i] && strs[j])
			if (!(ft_atoi(strs[i]) - ft_atoi(strs[j++])))
				return (0);
	}
	return (1);
}
