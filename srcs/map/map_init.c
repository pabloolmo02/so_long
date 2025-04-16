/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmo-lo <polmo-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:09:19 by polmo-lo          #+#    #+#             */
/*   Updated: 2025/04/16 17:41:39 by polmo-lo         ###   ########.fr       */
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
char **make_matrix(char *map_name, t_g *g, int i)
{
	char **matrix;
	char *matrix_line;
	int fd;
	
	fd = open(map_name, O_RDONLY);
	if (not_fd(fd))
		return(NULL);
	matrix = malloc(sizeof(char *) * (count_lines(map_name, g) + 1));
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