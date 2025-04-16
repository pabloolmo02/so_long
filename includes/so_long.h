/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmo-lo <polmo-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:14:02 by polmo-lo          #+#    #+#             */
/*   Updated: 2025/04/16 15:28:02 by polmo-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "unistd.h"
# include "./libs/get_next_line/get_next_line.h"
# include "./libs/libft/libft.h"
# include "./libs/ft_printf/ft_printf.h"
# include "MLX42/include/MLX42/MLX42.h"
# define PIXEL 64

typedef struct s_long
{
	char			**map;
	char			**map_copy;
	char			*name_map;
	int				collect;
	int				player;
	int				exit;
	int				height;
	int				width;
	int				x;
	int				y;
	int				count;
	int				moves;
	mlx_t			*init;
	mlx_image_t		*img_collect;
	mlx_image_t		*img_p;
	mlx_image_t		*img_exit;
	mlx_image_t		*img_f;
	mlx_image_t		*img_wall;
	mlx_texture_t	*texture;

}	t_g;

#endif