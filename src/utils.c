/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denpolat <denpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 03:15:46 by denpolat          #+#    #+#             */
/*   Updated: 2026/07/02 02:32:25 by denpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free (map[i]);
		i++;
	}
	free(map);
}

void	free_game(t_game *game)
{
	if (game->text_wall)
		mlx_destroy_image(game->mlx, game->text_wall);
	if (game->text_floor)
		mlx_destroy_image(game->mlx, game->text_floor);
	if (game->text_player)
		mlx_destroy_image(game->mlx, game->text_player);
	if (game->text_collect)
		 mlx_destroy_image(game->mlx, game->text_collect);
	if (game->text_exit)
		mlx_destroy_image(game->mlx, game->text_exit);
	if (game->map)
		free_map(game->map);
	if (game->copy)
		free_map(game->copy);
}
