/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denpolat <denpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 21:02:00 by denpolat          #+#    #+#             */
/*   Updated: 2026/07/01 04:31:47 by denpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	copy_ligne(t_game *game, int i)
{
	int	j;

	game->copy[i] = malloc(sizeof(char) * (game->nb_cols + 1));
	if (!game->copy[i])
	{
		free_game(game);
		exit(1);
	}
	j = 0;
	while (game->map[i][j])
	{
		game->copy[i][j] = game->map[i][j];
		j++;
	}
	game->copy[i][j] = '\0';
}

static void	copy_map(t_game *game)
{
	int	i;

	i = 0;
	game->copy = malloc(sizeof(char *) * (game->nb_lignes + 1));
	if (!game->copy)
	{
		free_game(game);
		exit(1);
	}
	while (game->map[i] != NULL)
	{
		copy_ligne(game, i);
		i++;
	}
	game->copy[i] = NULL;
}

static void	floodptn(t_game *game, int x, int y)
{
	if (game->copy[y][x] == '1' || game->copy[y][x] == 'F')
		return ;
	game->copy[y][x] = 'F';
	flodd(game, x + 1, y);
	flodd(game, x - 1, y);
	flood(game, x, y + 1);
	flood(game, x, y - 1);
}

int	flood_fill(t_game *game)
{
	int	i;
	int	j;

	copy_map(game);
	flood(game, game->player_x, game->player_y);
	i = 0;
	while (game->copy[i] != NULL)
	{
		j = 0;
		while (game->copy[i][j])
		{
			if (game->copy[i][j] == 'C' || game->copy[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
