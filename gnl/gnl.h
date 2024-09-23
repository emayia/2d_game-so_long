/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:16:02 by mayyildi          #+#    #+#             */
/*   Updated: 2022/10/28 17:18:01 by mayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include "../minilib/minilib.h"

/*		Manual definition of BUFFER_SIZE	*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*      Main functions      */
char	*put_line(char *str);
char	*fill_storage(char *s1, char *s2);
char	*update_storage(char *str);
char	*final_line(char **storage);
char	*gnl(int fd);

/*      Utilities           */
int		check_nl(char *str);

#endif
