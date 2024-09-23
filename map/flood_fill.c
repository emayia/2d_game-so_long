/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 07:46:07 by mayyildi          #+#    #+#             */
/*   Updated: 2022/11/03 08:22:18 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*	This function fills recursively our '0's on the map with 'F's.	*/
/*	If we run into 'C's or 'E's along the way, we also fill them w/	*/
/*	'F' characters.													*/
void	fill(char **arr, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| (arr[cur.y][cur.x] != to_fill && arr[cur.y][cur.x] != 'E'
		&& arr[cur.y][cur.x] != 'C'))
		return ;
	arr[cur.y][cur.x] = 'F';
	fill(arr, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(arr, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(arr, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(arr, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

/*	Here, after filling our map w/ 'F's, we parse it in order to see*/
/*	if there are any 'C's or 'E's left on our map (i.e. unreachable	*/
/*	because of walls). If that's the case we return (0).			*/
/*	Once the checks of whether map is valid or not are done, we free*/
/*	it using ft_free_arr() before returning (1).					*/
int	flood_fill(t_point start, t_head *head)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	head->map.flood[start.y][start.x] = '0';
	fill(head->map.flood, head->info->size, start, '0');
	while (head->map.flood[i])
	{
		j = 0;
		while (head->map.flood[i][j])
		{
			if (head->map.flood[i][j] == 'E' || head->map.flood[i][j] == 'C')
			{
				ft_free_arr(head->map.flood);
				return (0);
			}
			j++;
		}
		i++;
	}
	ft_free_arr(head->map.flood);
	return (1);
}
