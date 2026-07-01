/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denpolat <denpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 02:37:31 by denpolat          #+#    #+#             */
/*   Updated: 2026/07/01 03:33:19 by denpolat         ###   ########.fr       */
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

static int	count_valid(t_game *game)
{
	if (!count_arg(game, 0, 0, 0))
		return (0);
	return (1);
}

void	valid_map(t_game *game)
{
	if (!check_rectangle(game))
	{
		ft_putstr_fd("Error\nla map n est pas un rectangle chef\n", 2);
		free_map(game->map);
		exit(1);
	}
	else if (!is_one(game))
	{
		ft_putstr_fd("Error\nles murs sont pas des 1 chef\n", 2);
		free_map(game->map);
		exit(1);
	}
	else if (!count_valid(game))
	{
		ft_putstr_fd("Error\npas les bons char chef\n", 2);
		free_map(game->map);
		exit(1);
	}
}
