/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:16:56 by mayyildi          #+#    #+#             */
/*   Updated: 2022/11/03 18:10:08 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*	Simple function that handles errors:							*/
/*	• Step 0: Display error message on stderr						*/
/*	• Step 1: Exit program with EXIT_FAILURE option					*/
void	ft_error(char *err_msg)
{
	ft_putstr_fd("\e[0;31mError\e[0m", 2);
	ft_putstr_fd(err_msg, 2);
	exit(EXIT_FAILURE);
}
