/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denpolat <denpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 02:37:31 by denpolat          #+#    #+#             */
/*   Updated: 2026/06/30 05:01:37 by denpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_rectangle(char **map)
{
	int	firts_largeur;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][j] != '\0')
		j++;
	firts_largeur = j;
	j = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			j++;
		}
		if (j != firts_largeur)
			return (0);
		i++;
	}
	return (1);
}


static int	is_one(char **map)
{
	int	i;
	int	j;
	int	last_i;
	int	last_j;

	i = 0;
	j = 0;
	last_i = 0;
	last_j = ft_strlen(map[0]) - 1;
	while (map[last_i] != NULL)
		last_i++;
	last_i = last_i - 1;
	while (j <= last_j)
	{
		if (map[0][j] != '1' || map[last_i][j] != '1')
			return (0);
		j++;
	}
	while (i <= last_i)
	{
		if (map[i][0] != '1' || map[i][last_j] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	valid_map(char	**map_a_valid)
{
	if (!check_rectangle(map_a_valid))
	{
		ft_putstr_fd("Error\nla map n est pas un rectangle chef\n", 2);
		free_map(map_a_valid);
		exit(1);
	}
	if (!is_one)
	{
		ft_putstr_fd("Error\nles murs sont pas des 1 chef\n", 2);
		free_map(map_a_valid);
		exit(1);
	}
	
}