/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 07:38:27 by mayyildi          #+#    #+#             */
/*   Updated: 2022/10/28 07:41:05 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*dst;

	dst = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dst)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		dst[j++] = s1[i++];
	dst[j] = '\0';
	return (dst);
}
