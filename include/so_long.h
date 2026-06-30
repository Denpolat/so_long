/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denpolat <denpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 23:52:14 by denpolat          #+#    #+#             */
/*   Updated: 2026/06/30 23:07:53 by denpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include	<fcntl.h>
#include	"libft.h"
#include "get_next_line.h"


typedef struct s_game
{
	char	**map;
	char	**copy;
	int		nb_lignes;
	int		nb_cols;
	int		player_x;
	int		player_y;
	int		nb_collectibles;
}	t_game;

void	parse_map(char *file_name);
void	valid_map(t_game *game);

void	free_map(char **map);


#endif