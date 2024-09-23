/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 06:57:44 by mayyildi          #+#    #+#             */
/*   Updated: 2022/11/01 22:54:10 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (s && *s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	ft_putchar_fd(10, fd);
}
