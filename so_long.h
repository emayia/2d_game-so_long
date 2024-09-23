/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:17:36 by mayyildi          #+#    #+#             */
/*   Updated: 2022/11/03 19:08:03 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include <stdbool.h>
# include "mlx/mlx.h"
# include "gnl/gnl.h"
# include "minilib/minilib.h"

/*	-----	Structs	-----	*/
typedef struct s_map
{
	int		file;
	char	*full_line;
	char	**map;
	char	**flood;
}				t_map;

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_info
{
	int		p;
	int		c;
	int		e;
	int		width;
	int		height;
	t_point	size;
}				t_info;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	t_data	to_put;
}				t_mlx;

typedef struct s_head
{
	int		count;
	char	*file;
	t_mlx	mlx;
	t_map	map;
	t_info	*info;
	t_point	*pos;
	t_data	*img;
}				t_head;

/*	-----	Utils	-----	*/
/*	ft_arr_height.c	*/
int		ft_arr_height(char **str);
/*	ft_error.c	*/
void	ft_error(char *err_msg);
void	ft_success(char *success_msg, t_head *head);
/*	ft_init.c	*/
t_info	*init_info(void);
t_point	*init_pos(void);
/*	ft_mem.c	*/
void	ft_free_arr(char **str);

/*	-----	Map	-----	*/
/*	check_format.c	*/
int		check_format(char *filename);
/*	get_map.c	*/
void	get_map(char *av, t_head *head);
/*	check_map.c	*/
int		check_map(t_head *head);
int		check_map_shape(t_head *head);
int		check_map_walls(char **map);
void	check_char(t_head *head, char c, int x, int y);
int		check_map_content(t_head *head);
/*	flood_fill.c	*/
int		flood_fill(t_point start, t_head *head);
void	fill(char **arr, t_point size, t_point cur, char to_fill);
/*	display_map.c	*/
void	init_map(t_head *head);
void	display_map(t_head *head, t_data *img);
void	display_spt(t_head *head, t_data *img, t_point coord);
void	ft_spt(t_head *head, t_point coord, t_data img);
void	step_count(t_head *head, int y, void *img);
/*	update_map.c	*/
int		update_map(int keycode, t_head *head);
/*	move_player.c	*/
void	change_map_pos(t_head *head, int x, int y, bool is_collec);
void	move_w(t_point pos, char **map, t_head *head);
void	move_a(t_point pos, char **map, t_head *head);
void	move_s(t_point pos, char **map, t_head *head);
void	move_d(t_point pos, char **map, t_head *head);
/*	close_map.c	*/
int		ft_destroy_window(t_head *head);
int		close_button(t_head *head);

#endif
