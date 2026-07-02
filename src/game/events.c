/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denpolat <denpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 02:53:52 by denpolat          #+#    #+#             */
/*   Updated: 2026/07/02 03:45:30 by denpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player(t_game *game, int new_x, int new_y)
{
	char	tile;

	tile = game->map[new_y][new_x];
	if (tile == '1')
		return ;
	if (tile == 'E' && game->nb_collectibles > 0)
		return ;
	if (tile == 'E' && game->nb_collectibles == 0)
	{
		ft_putstr_fd("GG t'as gagné chef\n", 1);
		free_game(game);
		exit(0);
	}
	if (tile == 'C')
		game->nb_collectibles--;
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->movesamk++;
	ft_putnbr_fd(game->movesamk, 1);
	ft_putstr_fd(" moves\n", 1);
	render_map(game);
}

int key_hook(int keycode, t_game *game)
{
	 if (keycode == KEY_ESC)
	{
		free_game(game);
		exit(0);
	}
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, game->player_x, game->player_y - 1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, game->player_x, game->player_y + 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, game->player_x - 1, game->player_y);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, game->player_x + 1, game->player_y);
	return (0);
}

int	close_hook(t_game *game)
{
	free_game(game);
	exit(0);
}