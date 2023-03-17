/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyagiz <eyagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:32:57 by eyagiz            #+#    #+#             */
/*   Updated: 2023/01/23 14:28:00 by eyagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

static int	ft_isspace(char chr)
{
	if ((chr >= 9 && chr <= 13) || chr == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	unsigned long	ret_val;
	int				index;
	int				isaret;

	isaret = 1;
	index = 0;
	if (*nptr == '\0')
		return (0);
	while (ft_isspace(nptr[index]))
		index++;
	if (nptr[index] == '-' || nptr[index] == '+')
	{
		if (nptr[index] == '-')
			isaret *= -1;
		index++;
	}
	ret_val = 0;
	while (nptr[index] >= '0' && nptr[index] <= '9')
		ret_val = (ret_val * 10) + (nptr[index++] - '0');
	if (ret_val > LONG_MAX && isaret == -1)
		return (0);
	if (ret_val > LONG_MAX && isaret == 1)
		return (-1);
	return (ret_val * isaret);
}
