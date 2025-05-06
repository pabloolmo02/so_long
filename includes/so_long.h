/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmo-lo <polmo-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:14:02 by polmo-lo          #+#    #+#             */
/*   Updated: 2025/05/06 17:16:06 by polmo-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "unistd.h"
# include "libs/get_next_line/get_next_line.h"
# include "libs/libft/libft.h"
# include "libs/ft_printf/ft_printf.h"
# include "libs/MLX42/include/MLX42/MLX42.h"
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
	mlx_t			*mlx; //ventana
	mlx_image_t		*img_collect;
	mlx_image_t		*img_p;
	mlx_image_t		*img_exit;
	mlx_image_t		*img_f;
	mlx_image_t		*img_wall;
	mlx_texture_t	*texture;

}	t_g;

//TEXTURES
void	init_mlx_g(t_g *g);
void	load_textures(t_g *g);
void	put_textures(t_g *g);
void	put_floor(t_g *g);

//MAP
void 	check_dimension_and_content(t_g *g);
int 	map_line_checker(t_g *g, int i);
int map_chars(t_g *g);
void valid_format(char *map_name, t_g *g);
void parse_map(t_g *g, char *map_file, int i);
void init_struct_values(t_g *g);
char **make_matrix(char *map_file, t_g *g, int i);
int	count_lines(char *path, t_g *g);
void player_possition(t_g *g);

//MOVEMENTS
void	close_window(t_g *g);
void	set_moves(mlx_key_data_t key, void *param);
int		do_moves(t_g *g, int move);
void	move_up(t_g *g);
void	move_down(t_g *g);
void	move_right(t_g *g);
void	move_left(t_g *g);

//UTILS
char	**ft_free_map(char **map);
void	ft_printerrors(char *str, char **map, char **map_copy);
void	ft_error_free(char *msg, t_g *g);
int	not_fd(int fd);
int	ft_strlen_sl(char *s);
void check_start_and_final_line(char *str, t_g *g);
void flood_fill(t_g *g, int y, int x);
void valid_flood_fill(t_g *g);

#endif