/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmo-lo <polmo-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:52:23 by polmo-lo          #+#    #+#             */
/*   Updated: 2025/04/16 17:35:55 by polmo-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

char	**ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
	return (NULL);
}

void	ft_printerrors(char *str, char **map, char **map_copy)
{
	ft_free_map(map);
	ft_free_map(map_copy);
	ft_printf("ERROR: %s", str);
	exit(1);
}

void	ft_error_free(char *msg, t_g *g)
{
	(void)msg;
	ft_printf("ERROR: invalid map construction\n");
	if (!g->map)
		exit(1);
}

int	not_fd(int fd)
{
	if (fd < 0)
	{
		ft_printf("ERROR: Load Failed\n");
		return (1);
	}
	return (0);
}