/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 07:26:03 by mayyildi          #+#    #+#             */
/*   Updated: 2022/10/28 07:38:09 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] && s2[i]) && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}
