/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 05:37:25 by mayyildi          #+#    #+#             */
/*   Updated: 2022/11/02 22:33:58 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*	This function initializes the interactive content of our map,	*/
/*	such as the collectibles (c), the exit (e) and the player (p).	*/
/*	We set them all to 0 and then return the struct init_content.	*/
t_info	*init_info(void)
{
	t_info	*init_content;

	init_content = malloc(sizeof(t_info));
	init_content->c = 0;
	init_content->e = 0;
	init_content->p = 0;
	return (init_content);
}

/*	Here, we simply initialize pos and allocate the adequate amount	*/
/*	of memory to the struct before returning it.					*/
t_point	*init_pos(void)
{
	t_point	*pos;

	pos = malloc(sizeof(t_point));
	return (pos);
}
