/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denpolat <denpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 02:37:31 by denpolat          #+#    #+#             */
/*   Updated: 2026/06/30 23:04:07 by denpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_rectangle(t_game *game)
{
	int	firts_largeur;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i][j] != '\0')
		j++;
	firts_largeur = j;
	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			j++;
		}
		if (j != firts_largeur)
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

	i = 0;
	j = 0;
	last_i = game->nb_lignes - 1;
	last_j = game->nb_cols - 1;
	while (j <= last_j)
		last_i++;
	last_i = last_i - 1;
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
static int	valid_content(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1'
				 && game->map[i][j] != 'C'&& game->map[i][j] != 'E'
				  && game->map[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	count_valid(t_game *game)
{
	if (!count_arg(game->map, 0, 0, 0))
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
	else if (!is_one)
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