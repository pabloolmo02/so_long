/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmo-lo <polmo-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:05:48 by polmo-lo          #+#    #+#             */
/*   Updated: 2025/05/06 17:13:25 by polmo-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_dimension_and_content(t_g *g)
{
	if(g->height < 3 || g->width < 6)
		ft_printerrors("Wrong map size", g->map, g->map_copy);
	if (g->collect < 1)
		ft_printerrors("Wrong collect number", g->map, g->map_copy);
	if (g->exit != 1)
		ft_printerrors("Wrong exit number", g->map, g->map_copy);
}

int map_line_checker(t_g *g, int i)
{
	int j;

	j = 0;
	while(g->map[i][j])
	{
		if(g->map[i][0] != '1' || g->map[i][g->width - 1] != '1' )
			ft_printerrors("Incorrect characters\n", g->map, g->map_copy);
		if (g->map[i][j] != '1' && g->map[i][j] != '0'
			&& g->map[i][j] != 'E' && g->map[i][j] != 'P'
			&& g->map[i][j] != 'C' && g->map[i][j] != '\0'
			&& g->map[i][j] != '\n')
			ft_printerrors("Incorrect characters\n", g->map, g->map_copy);
		if(g->map[i][j] == 'P')
			g->player++;
		if(g->map[i][j] == 'C')
			g->collect++;
		if(g->map[i][j] == 'E')
			g->exit++;
		j++;
	}
	return (1);

}

int map_chars(t_g *g)
{
	int i;

	i = 0;
	check_start_and_final_line(g->map[i], g);
	check_start_and_final_line(g->map[g->height -1], g);
	while(g->map[i])
	{
		if(!map_line_checker(g, i))
			return (0);
		i++;
	}
	return (1);
}
void valid_format(char *map_name, t_g *g)
{
	int len;
	
	len = ft_strlen(map_name);
	if(len < 4)
	{
		ft_printerrors("map filename", g->map, g->map_copy);
		exit(1);
	}
	else
	{
		len--;
		if(map_name[len] != 'r' || map_name[len - 1] != 'e'
			|| map_name[len - 2] != 'b' || map_name[len - 3] != '.')
		{
			ft_printerrors("Map filename too short", g->map, g->map_copy);
			exit(1);
		}
	}
	g->name_map = map_name;
}
