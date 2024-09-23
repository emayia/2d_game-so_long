/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:05:12 by mayyildi          #+#    #+#             */
/*   Updated: 2022/11/01 21:23:35 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}
