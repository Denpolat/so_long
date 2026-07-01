/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denpolat <denpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 01:05:17 by denpolat          #+#    #+#             */
/*   Updated: 2026/07/01 04:44:54 by denpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	extension_check(char *file_name, int taille)
{
	if (taille < 4)
		return (0);
	if (ft_strncmp(file_name + (taille - 4), ".ber", 4) == 0)
		return (1);
	else
		return (0);
}

static void	add_line(t_game *game, char *ligne, int i)
{
	char	**tmp;
	int		len;

	len = ft_strlen(ligne);
	if (len > 0 && ligne[len - 1] == '\n')
		ligne[len - 1] = '\0';
	tmp = realloc(game->map, sizeof(char *) * (i + 2));
	if (tmp == NULL)
	{
		free(ligne);
		free_map(game->map);
		ft_putstr_fd("Error\nrealloc echoue zebi\n", 2);
		exit(1);
	}
	game->map = tmp;
	game->map[i] = ligne;
	game->map[i + 1] = NULL;
}

static void	store_map(t_game *game, int fd)
{
	char	*ligne;
	int		i;

	game->map = NULL;
	i = 0;
	ligne = get_next_line(fd);
	while (ligne != NULL)
	{
		add_line(game, ligne, i);
		i++;
		ligne = get_next_line(fd);
	}
	if (i == 0)
	{
		ft_putstr_fd("Error\nfichier vide chakal\n", 2);
		exit(1);
	}
	game->nb_lignes = i;
	game->nb_cols = ft_strlen(game->map[0]);
}

void	parse_map(char *file_name)
{
	size_t len;
	int		fd;
	t_game	game;

	len = ft_strlen(file_name);
	if (!extension_check(file_name, len))
	{
		ft_putstr_fd("Error\nMauvaise extension\n", 2);
		exit(1);
	}
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nimpossible d'ouvrir le fichier chef\n", 2);
		exit(1);
	}
	game.map = NULL;
	game.copy = NULL;
	store_map(&game, fd);
	close(fd);
	valid_map(&game);
	free_game(&game);
}