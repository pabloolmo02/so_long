/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmo-lo <polmo-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:45:06 by polmo-lo          #+#    #+#             */
/*   Updated: 2025/05/12 13:24:37 by polmo-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_mlx_g(t_g *g)
{
	g->mlx = mlx_init((g->width) * PIXEL,
			(g->height) * PIXEL, "so_long", false);
	if (!g->mlx)
		ft_printerrors("inizializating mlx g", g->map, g->map_copy);
	load_textures(g);
	put_textures(g);
	mlx_key_hook(g->mlx, set_moves, g);
	mlx_loop(g->mlx);
}

void	load_textures(t_g *g)
{
	g->texture = mlx_load_png("assets/player.png");
	if (!g->texture)
		ft_printerrors("failure creating p texture\n", g->map, g->map_copy);
	g->img_p = mlx_texture_to_image(g->mlx, g->texture);
	mlx_delete_texture(g->texture);
	g->texture = mlx_load_png("assets/wall.png");
	if (!g->texture)
		ft_printerrors("failure creating wall texture\n", g->map, g->map_copy);
	g->img_wall = mlx_texture_to_image(g->mlx, g->texture);
	mlx_delete_texture(g->texture);
	g->texture = mlx_load_png("assets/floor.png");
	if (!g->texture)
		ft_printerrors("failure creating floor texture\n", g->map, g->map_copy);
	g->img_f = mlx_texture_to_image(g->mlx, g->texture);
	mlx_delete_texture(g->texture);
	g->texture = mlx_load_png("assets/exit.png");
	if (!g->texture)
		ft_printerrors("failure creating exit texture\n", g->map, g->map_copy);
	g->img_exit = mlx_texture_to_image(g->mlx, g->texture);
	mlx_delete_texture(g->texture);
	g->texture = mlx_load_png("assets/collect.png");
	if (!g->texture)
		ft_printerrors("failure creating c texture\n", g->map, g->map_copy);
	g->img_collect = mlx_texture_to_image(g->mlx, g->texture);
	mlx_delete_texture(g->texture);
}

void	put_textures(t_g *g)
{
	int	x;
	int	y;

	y = 0;
	put_floor(g);
	while (g->height > y)
	{
		x = 0;
		while (g->map[y][x] != '\n' && g->map[y][x] != '\0')
		{
			if (g->map[y][x] == '1')
				mlx_image_to_window(g->mlx, g->img_wall,
					x * PIXEL, y * PIXEL);
			else if (g->map[y][x] == 'E')
				mlx_image_to_window(g->mlx, g->img_exit,
					x * PIXEL, y * PIXEL);
			else if (g->map[y][x] == 'C')
				mlx_image_to_window(g->mlx, g->img_collect,
					x * PIXEL, y * PIXEL);
			x++;
		}
		y++;
	}
	mlx_image_to_window(g->mlx, g->img_p,
		g->x * PIXEL, g->y * PIXEL);
}

void	put_floor(t_g *g)
{
	int	x;
	int	y;

	y = 0;
	while (g->height > y)
	{
		x = 0;
		while (g->map[y][x] != '\0' && g->map[y][x] != '\n')
		{
			mlx_image_to_window(g->mlx, g->img_f,
				x * PIXEL, y * PIXEL);
			x++;
		}
		y++;
	}
}
