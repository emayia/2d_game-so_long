/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:59:48 by mayyildi          #+#    #+#             */
/*   Updated: 2022/11/03 19:22:24 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*	This function displays the player's steps count. We first		*/
/*	display the menu bar below the map (wooden texture). Then we	*/
/*	join our msg str ("Step count: ")" w/ ft_itoa of our head->count*/
/*	and then we use mlx_string_put to display that msg on top.		*/
void	step_count(t_head *head, int y, void *img)
{
	int		x;
	char	*msg;
	char	*count;

	x = 0;
	while (x < ft_strlen(head->map.map[0]))
	{
		mlx_put_image_to_window(head->mlx.mlx, head->mlx.mlx_win,
			img, (x * 32), y * 32);
		x++;
	}
	msg = ft_strdup("Step count: ");
	count = ft_itoa(head->count);
	msg = ft_strjoin(msg, count);
	mlx_string_put(head->mlx.mlx, head->mlx.mlx_win,
		((head->info->width - 4) * 32) / 2, y * 32 + 22, 0, msg);
	free(msg);
	free(count);
}

/*	As mentioned down below, we first display our grass sprite and	*/
/*	then display one of our {1,C,E,P} sprite right on top of it.	*/
void	ft_spt(t_head *head, t_point coord, t_data img)
{
	mlx_put_image_to_window(head->mlx.mlx, head->mlx.mlx_win,
		head->img[0].img, (coord.x * 32), (coord.y * 32));
	mlx_put_image_to_window(head->mlx.mlx, head->mlx.mlx_win, img.img,
		(coord.x * 32), (coord.y * 32));
}

/*	Here we display just the grass if we have a '0' char. Else, we	*/
/*	call ft_spt to display the grass sprite first, and then display	*/
/*	the other sprite {1,C,E,P} on top of it, which adds some depth.	*/
void	display_spt(t_head *head, t_data *img, t_point coord)
{
	if (head->map.map[coord.y][coord.x] == '0')
		mlx_put_image_to_window(head->mlx.mlx, head->mlx.mlx_win,
			head->img[0].img, (coord.x * 32), (coord.y * 32));
	else if (head->map.map[coord.y][coord.x] == '1')
		ft_spt(head, coord, img[1]);
	else if (head->map.map[coord.y][coord.x] == 'C')
		ft_spt(head, coord, img[2]);
	else if (head->map.map[coord.y][coord.x] == 'E')
		ft_spt(head, coord, img[3]);
	else if (head->map.map[coord.y][coord.x] == 'P')
		ft_spt(head, coord, img[4]);
}

/*	This function goes through the map char by char and displays	*/
/*	the matching sprite based on their value. We also display our	*/
/*	steps counter on the last row, right below the map.				*/
void	display_map(t_head *head, t_data *img)
{
	int		i;
	int		j;
	char	*count;
	t_point	coord;

	i = 0;
	while (head->map.map[i])
	{
		j = 0;
		while (head->map.map[i][j])
		{
			coord.y = i;
			coord.x = j;
			display_spt(head, img, coord);
			j++;
		}
		i++;
	}
	count = ft_itoa(head->count);
	step_count(head, i, img[5].img);
	ft_putstr_fd(count, 1);
	free(count);
}

/*	All the previous checks are successfully passed, we can finally	*/
/*	jump right into this function that does the following:			*/
/*	• Allocate memory for our sprites								*/
/*	• Initialize mlx, new window, sprites 							*/
/*	• Set steps counter to 0										*/
/*	• Display map with sprites										*/
/*	• Add a mlx hook for the close button							*/
/*	• Call mlx_key_hook for the keyboard events	and call mlx_loop	*/
void	init_map(t_head *head)
{
	head->img = malloc(sizeof(t_data) * 6);
	head->mlx.mlx = mlx_init();
	head->mlx.mlx_win = mlx_new_window(head->mlx.mlx, head->info->width * 32,
			(head->info->height + 1) * 32, "so_long");
	head->img[0].img = mlx_xpm_file_to_image(head->mlx.mlx, "./spt/grass.xpm",
			&head->img[0].bits_per_pixel, &head->img[0].line_length);
	head->img[1].img = mlx_xpm_file_to_image(head->mlx.mlx, "./spt/wall.xpm",
			&head->img[1].bits_per_pixel, &head->img[1].line_length);
	head->img[2].img = mlx_xpm_file_to_image(head->mlx.mlx, "./spt/coin.xpm",
			&head->img[2].bits_per_pixel, &head->img[2].line_length);
	head->img[3].img = mlx_xpm_file_to_image(head->mlx.mlx, "./spt/chest.xpm",
			&head->img[3].bits_per_pixel, &head->img[3].line_length);
	head->img[4].img = mlx_xpm_file_to_image(head->mlx.mlx, "./spt/player.xpm",
			&head->img[4].bits_per_pixel, &head->img[4].line_length);
	head->img[5].img = mlx_xpm_file_to_image(head->mlx.mlx, "./spt/menu.xpm",
			&head->img[5].bits_per_pixel, &head->img[5].line_length);
	head->count = 0;
	display_map(head, head->img);
	mlx_hook(head->mlx.mlx_win, 17, 1L << 5, close_button, head);
	mlx_key_hook(head->mlx.mlx_win, update_map, head);
	mlx_loop(head->mlx.mlx);
}
