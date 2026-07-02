/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denpolat <denpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 23:52:14 by denpolat          #+#    #+#             */
/*   Updated: 2026/07/02 03:46:48 by denpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include	<fcntl.h>
#include	"libft.h"
#include	"get_next_line.h"
#include	"mlx.h"

#define TILE	64

#define EVT_KEYPRESS	2
#define EVT_DESTROY	17
#define MASK_KEYPRESS	1L

#define KEY_ESC	65307
#define KEY_W		119
#define KEY_A		97
#define KEY_S		115
#define KEY_D		100
#define KEY_UP		65362
#define KEY_DOWN	65364
#define KEY_LEFT	65361
#define KEY_RIGHT	65363


#define TEX_WALL	"textures/wall.xpm"
#define TEX_FLOOR	"textures/floor.xpm"
#define TEX_PLAYER	"textures/player.xpm"
#define TEX_COLLECT	"textures/collectible.xpm"
#define TEX_EXIT	"textures/exit.xpm"

typedef struct s_game
{
	char	**map;
	char	**copy;
	int		nb_lignes;
	int		nb_cols;
	int		player_x;
	int		player_y;
	int		nb_collectibles;
	int		nb_exit;
	int		nb_player;
	void	*mlx;
	void	*win;
	int		movesamk;
	void	*text_wall;
	void	*text_floor;
	void	*text_player;
	void	*text_collect;
	void	*text_exit;
}	t_game;

void	parse_map(char *file_name, t_game *game);
void	valid_map(t_game *game);
int	flood_fill(t_game *game);

void	free_map(char **map);
void	free_game(t_game *game);

void	init_jeux(t_game *game);
void	rendu_map(t_game *game);
int key_hook(int keycode, t_game *game);
int	close_hook(t_game *game);

#endif