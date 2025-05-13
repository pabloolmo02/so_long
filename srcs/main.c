/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmo-lo <polmo-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:53:08 by polmo-lo          #+#    #+#             */
/*   Updated: 2025/05/12 12:21:54 by polmo-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_g	g;

	if (argc != 2)
	{
		ft_printf("Error number of arguments \n");
		return (2);
	}
	else
	{
		parse_map(&g, argv[1], 0);
	}
	init_mlx_g(&g);
	g.map = ft_free_map(g.map);
	ft_free_map(g.map_copy);
	return (0);
}
