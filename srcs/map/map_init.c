/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmo-lo <polmo-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:09:19 by polmo-lo          #+#    #+#             */
/*   Updated: 2025/04/16 15:45:15 by polmo-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void init_struct_values(t_g *g)
{
	g->collect = 0;
	g->player = 0;
	g->exit = 0;
	g->height = 0;
	g->width = 0;
	g->height = 0;
	g->x = 0;
	g->y = 0;
	g->count = 0;
	g->moves = 0;
	g->map = NULL;
	g->map_copy = NULL;
	g->name_map = '\0';
	

}