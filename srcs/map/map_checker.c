/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmo-lo <polmo-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:05:48 by polmo-lo          #+#    #+#             */
/*   Updated: 2025/04/16 17:22:52 by polmo-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

//verificamos que el nombre del mapa es correcto y le asignamos su valor en la estructura: g->name_map = map_name;
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