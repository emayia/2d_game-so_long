/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:15:22 by mayyildi          #+#    #+#             */
/*   Updated: 2022/11/03 18:12:15 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*	This function does the following:								*/
/*	• If we press ESC (53), we successfully close our program		*/
/*	• Else if we press W (13) or ARROW_UP (126), we call move_w()	*/
/*	• Else if we press S (1) or ARROW_DOWN (125), we call move_s()	*/
/*	• Else if we press D (2) or ARROW_RIGHT (124), we call move_d()	*/
/*	• Else if we press A (0) or ARROW_LEFT (123), we call move_a()	*/
/*	We then return (1), as an int value is required by mlx_key_hook	*/
int	update_map(int keycode, t_head *head)
{
	if (keycode == 53)
		ft_success("Closed", head);
	else if (keycode == 13 || keycode == 126)
		move_w(*head->pos, head->map.map, head);
	else if (keycode == 1 || keycode == 125)
		move_s(*head->pos, head->map.map, head);
	else if (keycode == 2 || keycode == 124)
		move_d(*head->pos, head->map.map, head);
	else if (keycode == 0 || keycode == 123)
		move_a(*head->pos, head->map.map, head);
	return (1);
}
