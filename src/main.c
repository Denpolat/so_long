/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denpolat <denpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 00:36:00 by denpolat          #+#    #+#             */
/*   Updated: 2026/07/02 00:15:31 by denpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		write (1, "Error\n Usage: ./so_long <map.ber> chef\n", 39);
		return (1);
	}
	ft_memset(&game, 0, sizeof(t_game));
	parse_map(av[1], &game);
}