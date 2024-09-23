/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:35:55 by mayyildi          #+#    #+#             */
/*   Updated: 2022/11/01 23:04:39 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

static long int	ft_topos(long int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

static int	ft_intlen(long int nb)
{
	int		len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = nb * (-1);
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	int			sign;
	long int	nb;

	nb = n;
	sign = 0;
	if (nb < 0)
		sign = -1;
	str = malloc(sizeof(char) * (ft_intlen(nb) + 1));
	if (!str)
		return (NULL);
	str[ft_intlen(nb)] = '\0';
	len = ft_intlen(nb) - 1;
	while (len >= 0)
	{
		str[len] = '0' + ft_topos(nb % 10);
		nb = ft_topos(nb / 10);
		len--;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
