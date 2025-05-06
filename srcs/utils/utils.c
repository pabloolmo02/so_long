/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmo-lo <polmo-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:42:38 by polmo-lo          #+#    #+#             */
/*   Updated: 2025/05/06 17:13:04 by polmo-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_sl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

void	check_start_and_final_line(char *str, t_g *g)
{
	int	i;

	i = 0;
	while (str[i] == '1')
		i++;
	if (str[i] == '\0' || str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
		return ;
	else
		ft_printerrors("Incorrect characters\n", g->map, g->map_copy);
}

void	flood_fill(t_g *g, int y, int x)
{
	if (y < 0 || y >= g->height
		|| x < 0 || x >= g->width || g->map_copy[y][x] == '1')
		return ;
	g->map_copy[y][x] = '1';
	flood_fill(g, y - 1, x);
	flood_fill(g, y + 1, x);
	flood_fill(g, y, x - 1);
	flood_fill(g, y, x + 1);
}

void	valid_flood_fill(t_g *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->map_copy[y])
	{
		x = 0;
		while (g->map_copy[y][x])
		{
			if (((g->map_copy[y][x] == 'P')
				|| (g->map_copy[y][x] == 'C')
					|| (g->map_copy[y][x] == 'E')))
				ft_printerrors("Invalid map\n", g->map, g->map_copy);
			x++;
		}
		y++;
	}
}
