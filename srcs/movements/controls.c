/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmo-lo <polmo-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:51:41 by polmo-lo          #+#    #+#             */
/*   Updated: 2025/05/06 17:12:35 by polmo-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_g *g)
{
	if (do_moves(g, 1) == 1)
	{
		if (g->map[g->y][g->x] == 'C')
		{
			g->count++;
			g->map[g->y][g->x] = '0';
			mlx_image_to_window(g->mlx, g->img_f,
				g->x * PIXEL, g->y * PIXEL);
			mlx_delete_image(g->mlx, g->img_p);
			g->texture = mlx_load_png("images/player.png");
			if (!g->texture)
				ft_printerrors("loading player texture", g->map, g->map_copy);
			g->img_p = mlx_texture_to_image(g->mlx, g->texture);
			mlx_image_to_window(g->mlx, g->img_p, g->x * PIXEL, g->y * PIXEL);
			mlx_delete_texture(g->texture);
		}
		else if (g->map[g->y][g->x] == 'E' && g->count == g->collect)
		{
			g->moves++;
			ft_printf("Moves: %d\n", g->moves);
			close_window(g);
		}
		g->moves++;
		ft_printf("Moves: %d\n", g->moves);
	}
}

void	move_down(t_g *g)
{
	if (do_moves(g, 2) == 1)
	{
		if (g->map[g->y][g->x] == 'C')
		{
			g->count++;
			g->map[g->y][g->x] = '0';
			mlx_image_to_window(g->mlx, g->img_f, g->x * PIXEL, g->y * PIXEL);
			mlx_delete_image(g->mlx, g->img_p);
			g->texture = mlx_load_png("images/player.png");
			if (!g->texture)
				ft_printerrors("loading player texture", g->map, g->map_copy);
			g->img_p = mlx_texture_to_image(g->mlx, g->texture);
			mlx_image_to_window(g->mlx, g->img_p, g->x * PIXEL, g->y * PIXEL);
			mlx_delete_texture(g->texture);
		}
		else if (g->map[g->y][g->x] == 'E' && g->count == g->collect)
		{
			g->moves++;
			ft_printf("Moves: %d\n", g->moves);
			close_window(g);
		}
		g->moves++;
		ft_printf("Moves: %d\n", g->moves);
	}
}

void	move_right(t_g *g)
{
	if (do_moves(g, 3) == 1)
	{
		if (g->map[g->y][g->x] == 'C')
		{
			g->count++;
			g->map[g->y][g->x] = '0';
			mlx_image_to_window(g->mlx, g->img_f, g->x * PIXEL, g->y * PIXEL);
			mlx_delete_image(g->mlx, g->img_p);
			g->texture = mlx_load_png("images/player.png");
			if (!g->texture)
				ft_printerrors("loading player texture", g->map, g->map_copy);
			g->img_p = mlx_texture_to_image(g->mlx, g->texture);
			mlx_image_to_window(g->mlx, g->img_p, g->x * PIXEL, g->y * PIXEL);
			mlx_delete_texture(g->texture);
		}
		else if (g->map[g->y][g->x] == 'E' && g->count == g->collect)
		{
			g->moves++;
			ft_printf("Moves: %d\n", g->moves);
			close_window(g);
		}
		g->moves++;
		ft_printf("Moves: %d\n", g->moves);
	}
}

void	move_left(t_g *g)
{
	if (do_moves(g, 4) == 1)
	{
		if (g->map[g->y][g->x] == 'C')
		{
			g->count++;
			g->map[g->y][g->x] = '0';
			mlx_image_to_window(g->mlx, g->img_f, g->x * PIXEL, g->y * PIXEL);
			mlx_delete_image(g->mlx, g->img_p);
			g->texture = mlx_load_png("images/player.png");
			if (!g->texture)
				ft_printerrors("loading player texture", g->map, g->map_copy);
			g->img_p = mlx_texture_to_image(g->mlx, g->texture);
			mlx_image_to_window(g->mlx, g->img_p, g->x * PIXEL, g->y * PIXEL);
			mlx_delete_texture(g->texture);
		}
		else if (g->map[g->y][g->x] == 'E' && g->count == g->collect)
		{
			g->moves++;
			ft_printf("Moves: %d\n", g->moves);
			close_window(g);
		}
		g->moves++;
		ft_printf("Moves: %d\n", g->moves);
	}
}

