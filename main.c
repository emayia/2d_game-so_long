/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 06:47:47 by mayyildi          #+#    #+#             */
/*   Updated: 2022/11/02 22:24:01 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*	First, we verify the args' count. Then we verify that the user	*/
/*	provides the right file extension. After that, we create two	*/
/*	copies of the map we just read, a main copy and another one for	*/
/*	the flood_fill() function. In the final section of our main(),	*/
/*	we check the map's shape, its surrounding walls, its content,	*/
/*	and lastly, if the player has a valid path [flood_fill()].		*/
/*	If we pass all these tests, we can finally initialize our map	*/
/*	and start playing the game.*/
int	main(int ac, char **av)
{
	t_head	head;

	if (ac != 2)
		ft_error("Invalid arguments count");
	if (!check_format(av[1]))
		ft_error("Invalid file format");
	get_map(av[1], &head);
	if (check_map(&head))
		init_map(&head);
	return (0);
}
