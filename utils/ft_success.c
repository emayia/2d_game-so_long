/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_success.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:50:59 by mayyildi          #+#    #+#             */
/*   Updated: 2022/11/03 19:21:49 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*	Simple function that handles success cases:						*/
/*	• Step 0: Display success message on stdout						*/
/*	• Step 1: Free sprites and the whole map						*/
/*	• Step 3: Exit program with EXIT_SUCCESS option					*/
void	ft_success(char *success_msg, t_head *head)
{
	ft_putstr_fd("\e[0;32mSuccess\e[0m", 1);
	ft_putstr_fd(success_msg, 1);
	free(head->img);
	ft_free_arr(head->map.map);
	exit(EXIT_SUCCESS);
}
