/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 08:23:32 by mayyildi          #+#    #+#             */
/*   Updated: 2022/11/03 08:23:37 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*	Here, we first store the name of the map within our head struct.*/
/*	Then, we open the file and check if it's a file or directory.	*/
/*	After that, we copy the content of our map on a single line		*/
/*	using gnl() and ft_strjoin() in a loop.							*/
/*	Once that's done, we split that full_line into our main map and	*/
/*	a test one for flood_fill().									*/
void	get_map(char *av, t_head *head)
{
	char	*tmp;

	head->file = ft_strdup(av);
	head->map.file = open(av, O_RDONLY);
	if (head->map.file < 0 || open(av, O_DIRECTORY) > 0)
		ft_error("Incorrect file");
	tmp = gnl(head->map.file);
	if (!tmp)
		ft_error("Map is empty");
	head->map.full_line = ft_strdup(tmp);
	while (tmp)
	{
		free(tmp);
		tmp = gnl(head->map.file);
		if (!tmp)
			break ;
		head->map.full_line = ft_strjoin(head->map.full_line, tmp);
	}
	free(tmp);
	head->map.map = ft_split(head->map.full_line, '\n');
	head->map.flood = ft_split(head->map.full_line, '\n');
	close(head->map.file);
}
