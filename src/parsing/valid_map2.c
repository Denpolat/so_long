/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denpolat <denpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 21:02:00 by denpolat          #+#    #+#             */
/*   Updated: 2026/07/01 00:30:14 by denpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_arg(t_game *game, int p, int e, int c)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				p++;
			else if (game->map[i][j] == 'E')
				e++;
			else if (game->map[i][j] == 'C')
				c++;
			else if (game->map[i][j] != '0' && game->map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	if (p != 1 || e != 1 || c < 1)
		return (0);
	return (1);
}
static void	copy_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->copy = malloc(sizeof(char *) * (game->nb_lignes + 1));
	while (game->map[i] != NULL)
	{
		game->copy[i] = malloc(sizeof (char) * (game->nb_cols + 1));
		j = 0;
		while (game->map[i][j])
		{
			game->copy[i][j] = game->map[i][j];
			j++;
		}
		game->copy[i][j] = '\0';
		i++;
	}
	game->copy[i] = NULL;
}

int	flood_fill(t_game *game)
{
	copy_map(game->copy);
}
