/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denpolat <denpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 01:05:17 by denpolat          #+#    #+#             */
/*   Updated: 2026/06/30 02:47:55 by denpolat         ###   ########.fr       */
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

static char	**store_map(int fd)
{
	char	**map;
	char	*ligne;
	int		i;

	map = NULL;
	i = 0;
	ligne = get_next_line(fd);
	while (ligne != NULL)
	{
		map = realloc(map, sizeof(char *) * (i + 2));
		map[i] = ligne;
		map[i + 1] = NULL;
		i++;
		ligne = get_next_line(fd);
	}
	return (map);
}

void	parse_map(char *file_name)
{
	size_t len;
	int		fd;
	char	**map;

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
	map = store_map(fd);
	close(fd);
	valid_map(map);
}