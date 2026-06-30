/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denpolat <denpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 23:52:14 by denpolat          #+#    #+#             */
/*   Updated: 2026/06/30 03:18:31 by denpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include	<fcntl.h>
#include	"libft.h"
#include "get_next_line.h"

void	parse_map(char *file_name);
void	valid_map(char	**map_a_valid);

void	free_map(char **map);


#endif