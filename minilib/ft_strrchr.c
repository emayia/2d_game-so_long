/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:15:12 by mayyildi          #+#    #+#             */
/*   Updated: 2022/10/28 09:17:09 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *) s;
	i = ft_strlen(s);
	while (str[i] != (unsigned char) c)
	{
		if (i == 0)
			return (NULL);
		i--;
	}
	return (str + i);
}
