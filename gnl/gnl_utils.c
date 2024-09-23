/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:20:30 by mayyildi          #+#    #+#             */
/*   Updated: 2022/10/28 10:20:45 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

/*	This function checks if there is a nl character within the str. */
/*	RETURN VALUES:													*/
/*	• (1): found nl													*/
/*	• (0): nl not found												*/
int	check_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
