/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:47:16 by mayyildi          #+#    #+#             */
/*   Updated: 2022/11/03 14:50:57 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*	This function checks whether or not the file provided by		*/
/*	the user has the correct '.ber' extention.						*/
int	check_format(char *filename)
{
	int		i;
	char	*ext;

	i = 0;
	while (filename[i])
	{
		if (!ft_strchr(filename, '.'))
			return (0);
		ext = ft_strrchr(filename, '.');
		if (ft_strcmp(ext, ".ber") < 0 || ft_strcmp(ext, ".ber") > 0)
			return (0);
		i++;
	}
	return (1);
}
