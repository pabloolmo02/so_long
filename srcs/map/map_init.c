/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmo-lo <polmo-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:09:19 by polmo-lo          #+#    #+#             */
/*   Updated: 2025/05/12 13:38:20 by polmo-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	parse_map(t_g *g, char *map_file, int i)
{
	i = 0;
	init_struct_values(g);
	valid_format(map_file, g);
	g->map = make_matrix(map_file, g, i);
	if (!g->map)
		ft_printerrors("map error 1\n", g->map, g->map_copy);
	g->map_copy = make_matrix(map_file, g, i);
	if (!g->map_copy)
		ft_printerrors("map error 2\n", g->map, g->map_copy);
	map_chars(g);
	check_dimension_and_content(g);
	player_possition(g);
	flood_fill(g, (g->y), (g->x));
	valid_flood_fill(g);
}

void	init_struct_values(t_g *g)
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

char	**make_matrix(char *map_file, t_g *g, int i)
{
	char	**matrix;
	char	*matrix_line;
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (not_fd(fd))
		return (NULL);
	matrix = malloc(sizeof(char *) * (count_lines(map_file, g) + 1));
	if (!matrix)
		ft_printerrors("memory fail in matrix\n", g->map, g->map_copy);
	matrix_line = get_next_line(fd);
	if (!matrix_line)
		ft_printerrors("memory fail in matrix\n", g->map, g->map_copy);
	while (matrix_line)
	{
		matrix[i] = ft_strdup(matrix_line);
		free(matrix_line);
		matrix_line = get_next_line(fd);
		i++;
	}
	g->height = i;
	matrix[i] = NULL;
	free(matrix_line);
	return (matrix);
}

int	count_lines(char *path, t_g *g)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	if (!path)
		ft_printerrors("Path not found\n", g->map, g->map_copy);
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	g->width = ft_strlen_sl(line);
	if (!line)
		ft_printerrors("Invalid map\n", g->map, g->map_copy);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
		if (line && g->width != ft_strlen_sl(line))
			(free(line), get_next_line(fd), ft_error_free(path, g));
	}
	close(fd);
	free(line);
	line = NULL;
	return (i);
}

void	player_possition(t_g *g)
{
	int	i;
	int	j;

	i = 0;
	if (g->player != 1)
		ft_printerrors("Wrong player number\n", g->map, g->map_copy);
	while (i < g->height)
	{
		j = 0;
		while (g->map[i][j] != '\0')
		{
			if (g->map[i][j] == 'P')
			{
				g->x = j;
				g->y = i;
			}
			j++;
		}
		i++;
	}
}
