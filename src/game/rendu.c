/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denpolat <denpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 02:34:16 by denpolat          #+#    #+#             */
/*   Updated: 2026/07/02 02:46:34 by denpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	rendu_tile(t_game *game, int i, int j)
{
	char	c;

	c = game->map[i][j];
	mlx_put_image_to_window(game->mlx, game->win,
		game->text_floor, j * TILE, i * TILE);
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->text_wall, j * TILE, i * TILE);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->text_collect, j * TILE, i * TILE);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->text_exit, j * TILE, i * TILE);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->text_player, j * TILE, i * TILE);
}

void	rendu_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j])
		{
			rendu_tile(game, i, j);
			j++;
		}
		i++;
	}
}
