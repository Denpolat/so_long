/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denpolat <denpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 04:56:10 by denpolat          #+#    #+#             */
/*   Updated: 2026/07/02 03:50:20 by denpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static	void	charge_texture(t_game *game, void **tex, char *path)
{
	int	w;
	int	h;

	*tex = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	if (!(*tex))
	{
		ft_putstr_fd("Error\nimpossible de charger map bg\n", 2);
		free_game(game);
		exit(1);
	}
}

static void	charge_textures(t_game *game)
{
	charge_texture(game, &game->text_wall, TEX_WALL);
	charge_texture(game, &game->text_floor, TEX_FLOOR);
	charge_texture(game, &game->text_player, TEX_PLAYER);
	charge_texture(game, &game->text_collect, TEX_COLLECT);
	charge_texture(game, &game->text_exit, TEX_EXIT);
}


void	init_jeux(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error\nmix_init a echoue cheh\n", 2);
		free_game(game);
		exit(1);
	}
	game->win = mlx_new_window(game->mlx,
			game->nb_cols * TILE,
			game->nb_lignes * TILE,
			"so_long");
	if(!game->win)
	{
		ft_putstr_fd("Error\nmlx_new_w echoue\n", 2);
		free_game(game);
		exit(1);
	}
	charge_textures(game);
	rendu_map(game);
	mlx_hook(game->win, EVT_KEYPRESS, MASK_KEYPRESS, key_hook, game);
	mlx_hook(game->win, EVT_DESTROY, 0, close_hook, game);
	mlx_loop(game->mlx);
}
