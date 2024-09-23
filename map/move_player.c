/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:40:00 by mayyildi          #+#    #+#             */
/*   Updated: 2022/11/03 18:02:30 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*	Here we first check if our char is a collectible, if that's		*/
/*	the case, we decrement our collectible's counter by 1.			*/
/*	Once that's done, we turn our current char into grass '0', and	*/
/*	the next one into a player sprite 'P'.							*/
/*	We then display our grass sprite, and on our new player pos, we	*/
/*	display our player's sprite.									*/
/*	After that, we update our x and y pos coordinates and increment	*/
/*	our steps counter by 1.											*/
/*	Once that's done, we print our new step count value by calling	*/
/*	step_count() to re-display the menu bar below the map w/ the	*/
/*	updated step count and then also display that value followed by	*/
/*	a newline on our terminal by calling ft_putstr_fd() and itoa()	*/
/*	of our step count.												*/
void	change_map_pos(t_head *head, int x, int y, bool is_collec)
{
	char	*count;

	if (is_collec == true)
		head->info->c--;
	head->map.map[head->pos->y][head->pos->x] = '0';
	head->map.map[head->pos->y + y][head->pos->x + x] = 'P';
	mlx_put_image_to_window(head->mlx.mlx, head->mlx.mlx_win, head->img[0].img,
		head->pos->x * 32, head->pos->y * 32);
	mlx_put_image_to_window(head->mlx.mlx, head->mlx.mlx_win, head->img[4].img,
		(head->pos->x + x) * 32, (head->pos->y + y) * 32);
	head->pos->y = head->pos->y + y;
	head->pos->x = head->pos->x + x;
	head->count++;
	count = ft_itoa(head->count);
	step_count(head, head->info->height, head->img[5].img);
	ft_putstr_fd(count, 1);
	free(count);
}

/*	This is our move up function. We run the following tests:		*/
/*	• If the element above is a wall, simply return ;				*/
/*	• Else if the element above is grass, we call our function		*/
/*	change_map_pos() in order to update our player's position and	*/
/*	since grass isn't a collectible, we set it's is_collec value to	*/
/*	false <stdbool.h>. The opposite goes to our 'C' char, since it's*/
/*	a collectible, we set its value to true.						*/
/*	• Else if the element above is the exit 'E', if my collectible's*/
/*	counter is at 0 (i.e. we took all of them on the map), then we	*/
/*	successfully exit w/ a success message.							*/
void	move_w(t_point pos, char **map, t_head *head)
{
	if (map[pos.y - 1][pos.x] == '1')
		return ;
	else if (map[pos.y - 1][pos.x] == '0')
		change_map_pos(head, 0, -1, false);
	else if (map[pos.y - 1][pos.x] == 'C')
		change_map_pos(head, 0, -1, true);
	else if (map[pos.y - 1][pos.x] == 'E')
		if (head->info->c == 0)
			ft_success("You won", head);
}

/*	This is our move down function. We run the following tests:		*/
/*	• If the element below is a wall, simply return ;				*/
/*	• Else if the element below is grass, we call our function	*/
/*	change_map_pos() in order to update our player's position and	*/
/*	since grass isn't a collectible, we set it's is_collec value to	*/
/*	false <stdbool.h>. The opposite goes to our 'C' char, since it's*/
/*	a collectible, we set its value to true.						*/
/*	• Else if the element below is the exit 'E', if my collectible's*/
/*	counter is at 0 (i.e. we took all of them on the map), then we	*/
/*	successfully exit w/ a success message.							*/
void	move_s(t_point pos, char **map, t_head *head)
{
	if (map[pos.y + 1][pos.x] == '1')
		return ;
	else if (map[pos.y + 1][pos.x] == '0')
		change_map_pos(head, 0, 1, false);
	else if (map[pos.y + 1][pos.x] == 'C')
		change_map_pos(head, 0, 1, true);
	else if (map[pos.y + 1][pos.x] == 'E')
		if (head->info->c == 0)
			ft_success("You won", head);
}

/*	This is our move right function. We run the following tests:	*/
/*	• If the element on my right is a wall, simply return ;			*/
/*	• Else if the element on my right is grass, we call our function*/
/*	change_map_pos() in order to update our player's position and	*/
/*	since grass isn't a collectible, we set it's is_collec value to	*/
/*	false <stdbool.h>. The opposite goes to our 'C' char, since it's*/
/*	a collectible, we set its value to true.						*/
/*	• Else if the element on my right is the exit 'E', if my		*/
/*	collectible's counter is at 0 (i.e. we took all of them on the	*/
/*	map), then we successfully exit w/ a success message.			*/
void	move_d(t_point pos, char **map, t_head *head)
{
	if (map[pos.y][pos.x + 1] == '1')
		return ;
	else if (map[pos.y][pos.x + 1] == '0')
		change_map_pos(head, 1, 0, false);
	else if (map[pos.y][pos.x + 1] == 'C')
		change_map_pos(head, 1, 0, true);
	else if (map[pos.y][pos.x + 1] == 'E')
		if (head->info->c == 0)
			ft_success("You won", head);
}

/*	This is our move left function. We run the following tests:		*/
/*	• If the element on my left is a wall, simply return ;			*/
/*	• Else if the element on my left is grass, we call our function	*/
/*	change_map_pos() in order to update our player's position and	*/
/*	since grass isn't a collectible, we set it's is_collec value to	*/
/*	false <stdbool.h>. The opposite goes to our 'C' char, since it's*/
/*	a collectible, we set its value to true.						*/
/*	• Else if the element on my left is the exit 'E', if my			*/
/*	collectible's counter is at 0 (i.e. we took all of them on the	*/
/*	map), then we successfully exit w/ a success message.			*/
void	move_a(t_point pos, char **map, t_head *head)
{
	if (map[pos.y][pos.x - 1] == '1')
		return ;
	else if (map[pos.y][pos.x - 1] == '0')
		change_map_pos(head, -1, 0, false);
	else if (map[pos.y][pos.x - 1] == 'C')
		change_map_pos(head, -1, 0, true);
	else if (map[pos.y][pos.x - 1] == 'E')
		if (head->info->c == 0)
			ft_success("You won", head);
}
