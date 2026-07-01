/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denpolat <denpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 01:05:17 by denpolat          #+#    #+#             */
/*   Updated: 2026/07/02 00:08:44 by denpolat         ###   ########.fr       */
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

static int	count_lignes(char *file_name)
{
	int		fd;
	char	*lignes;
	int		count;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	lignes = get_next_line(fd);
	while (lignes != NULL)
	{
		count++;
		free(lignes);
		lignes = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static void	enleve_newlineptn(char *ligne)
{
	int	len;

	len = ft_strlen(ligne);
	if (len > 0 && ligne[len - 1] == '\n')
		ligne[len - 1] = '\0';

}

static void	store_map(t_game *game, int fd, char *file_name)
{
	char	*ligne;
	int		nb;
	int		i;

	nb = count_lignes(file_name);
	if (nb <= 0)
	{
		ft_putstr_fd("Error\nfichier vide zebi", 2);
		exit(1);
	}
	game->map = malloc(sizeof(char *) * (nb + 1));
	if (!game->map)
		exit(1);
	game->map[nb] = NULL;
	i = 0;
	ligne = get_next_line(fd);
	while (ligne != NULL)
	{
		enleve_newlineptn(ligne);
		game->map[i] = ligne;
		i++;
		ligne = get_next_line(fd);
	}
	game->nb_lignes = nb;
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
	ft_memset(&game, 0, sizeof(t_game));
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nimpossible d'ouvrir le fichier chef\n", 2);
		exit(1);
	}
	store_map(&game, fd, file_name);
	close(fd);
	valid_map(&game);
	free_game(&game);
}