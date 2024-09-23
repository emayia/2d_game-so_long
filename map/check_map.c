/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:51:00 by mayyildi          #+#    #+#             */
/*   Updated: 2022/11/03 14:59:38 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*	This function helps us verify if our map is a rectangle.		*/
/*	If it's a square or any other shape, we return (0). Else, we	*/
/*	have a valid rectangle on our hands and thus return (1).		*/
int	check_map_shape(t_head *head)
{
	int	i;

	i = 0;
	head->info = init_info();
	head->info->width = ft_strlen(head->map.map[i++]);
	head->info->height = ft_arr_height(head->map.map);
	head->info->size.y = head->info->height;
	head->info->size.x = head->info->width;
	while (head->map.map[i])
	{
		if (ft_strlen(head->map.map[i]) != head->info->width)
			return (0);
		i++;
	}
	if (head->info->height == head->info->width)
		return (0);
	return (1);
}

/*	We verify through this function if our map is surrounded *only*	*/
/*	by walls or not. If any of the surrounding chars isn't a wall,	*/
/*	return (0), else, return (1).									*/
int	check_map_walls(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(map[i]) - 1;
	while (map[i])
	{
		if ((i == 0) || (i == ft_arr_height(map) - 1))
		{
			j = 0;
			while (map[i][j])
			{
				if (map[i][j++] != '1')
					return (0);
			}
		}
		else if (map[i][0] != '1' || map[i][len] != '1')
			return (0);
		i++;
	}
	return (1);
}

/*	While we check if the current char is one of these: {01cep},	*/
/*	we also do the following:										*/
/*	• Increment c if we run into a 'C' char							*/
/*	• Set our player's position on the map and check if only 1 'P'	*/
/*	• Check if multiple exits within the map						*/
void	check_char(t_head *head, char c, int x, int y)
{
	if (c == 'C')
		head->info->c++;
	else if (c == 'P')
	{
		if (head->info->p == 1)
			ft_error("Multiple players");
		head->pos->x = x;
		head->pos->y = y;
		head->info->p++;
	}
	else if (c == 'E')
	{
		if (head->info->e == 1)
			ft_error("Multiple exits");
		head->info->e++;
	}
	else if (c != '1' && c != '0')
		ft_error("Invalid content");
}

/*	Here, we verify the contents of our map and initialize the pos	*/
/*	of our player. We'll check the map char by char w/ check_char().*/
int	check_map_content(t_head *head)
{
	int		i;
	int		j;

	i = 0;
	head->pos = init_pos();
	while (head->map.map[i])
	{
		j = 0;
		while (head->map.map[i][j])
		{
			check_char(head, head->map.map[i][j], j, i);
			j++;
		}
		i++;
	}
	return (1);
}

/*	We check all of the conditions below: if any of it isn't valid,	*/
/*	we display the adequate error message. Else, we return (1),		*/
/*	which is our green light in main() to run init_map().			*/
int	check_map(t_head *head)
{
	if (!check_map_shape(head))
		ft_error("Map shape isn't valid");
	else if (!check_map_walls(head->map.map))
		ft_error("Surrounding walls aren't valid");
	else if (!check_map_content(head))
		ft_error("Incorrect map content");
	else if (!flood_fill(*head->pos, head))
		ft_error("No valid path found");
	return (1);
}
