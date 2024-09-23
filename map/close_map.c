/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 02:01:08 by mayyildi          #+#    #+#             */
/*   Updated: 2022/11/03 19:10:08 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*	This function closes our window whenever we reach the exit or	*/
/*	press the ESC button while playing the game.					*/
int	ft_destroy_window(t_head *head)
{
	mlx_destroy_window(head->mlx.mlx_win, head->mlx.mlx);
	ft_success("Window closed", head);
	return (1);
}

/*	This one closes our game window whenever we click on the close	*/
/*	button on the top-left side of our window.						*/
int	close_button(t_head *head)
{
	ft_success("Window closed", head);
	return (0);
}
