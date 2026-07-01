/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denpolat <denpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 02:37:31 by denpolat          #+#    #+#             */
/*   Updated: 2026/07/01 04:40:36 by denpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_rectangle(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		if ((int)ft_strlen(game->map[i]) != game->nb_cols)
			return (0);
		i++;
	}
	return (1);
}

static int	is_one(t_game *game)
{
	int	i;
	int	j;
	int	last_i;
	int	last_j;

	last_i = game->nb_lignes - 1;
	last_j = game->nb_cols - 1;
	j = 0;
	i = 0;
	while (j <= last_j)
	{
		if (game->map[0][j] != '1' || game->map[last_i][j] != '1')
			return (0);
		j++;
	}
	while (i <= last_i)
	{
		if (game->map[i][0] != '1' || game->map[i][last_j] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_char(t_game *game, int i, int j)
{
	char	c;

	c = game->map[i][j];
	if (c == 'P')
	{
		game->nb_player++;
		game->player_x = j;
		game->player_y = i;
	}
	else if (c == 'E')
		game->nb_exit++;
	else if (c == 'C')
		game->nb_collectibles++;
	else if (c != '0' && c != '1')
		return (0);
	return (1); 
}

static int	count_arg(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!check_char(game, i, j))
				return (0);
			j++;
		}
		i++;
	}
	if (game->nb_player != 1 || game->nb_exit != 1 ||
		 game->nb_collectibles < 1)
		return (0);
	return (1);
}

void	valid_map(t_game *game)
{
	if (!check_rectangle(game))
	{
		ft_putstr_fd("Error\nla map n est pas un rectangle chef\n", 2);
		free_game(game);
		exit(1);
	}
	else if (!is_one(game))
	{
		ft_putstr_fd("Error\nles murs sont pas des 1 chef\n", 2);
		free_game(game);
		exit(1);
	}
	else if (!count_arg(game))
	{
		ft_putstr_fd("Error\npas les bons char chef\n", 2);
		free_game(game);
		exit(1);
	}
	else if (!flood_fill(game))
	{
		ft_putstr_fd("Error\nmap invalide chef\n", 2);
		free_game(game);
		exit(1);
	}
}
