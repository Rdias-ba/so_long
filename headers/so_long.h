/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:58:04 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/25 04:13:26 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../mlx/mlx.h"

# define KEYPRESS 2
# define KEYRELEASE 3
# define KEY_ESC 65307
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_W 119

typedef struct s_img_data
{
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_player_u;
	void	*img_player_r;
	void	*img_player_d;
	void	*img_player_l;
	void	*img_collectible;
	void	*img_exit;
	int		img_x;
	int		img_y;
}			t_img_data;

typedef struct s_elem_data
{
	int		items;
	int		player;
	int		p_y;
	int		p_x;
	int		exits;
	int		e_y;
	int		e_x;
}			t_elem_data;

typedef struct s_game_data
{
	void		*mlx;
	void		*mlx_win;
	char		**map;
	int			map_y;
	int			map_x;
	int			c_found;
	int			e_found;
	int			steps;
	t_elem_data	elems;
	t_img_data	imgs;
}			t_game_data;

void	error_message(char *str);
void	mapping(char **argv, t_game_data *data);
void	free_map(char **map);
void	free_map_data(t_game_data *data);
int		check_walls(t_game_data *data);
void	error_message_free(t_game_data *data, char *str);
int		check_rectangle(t_game_data *data);
int		check_ingame(t_game_data *data);
int		check_playable(t_game_data *data);
void	open_game(t_game_data *data);
void	images_init(t_game_data *data);
void	put_images_from_data(t_game_data *data);
void	destroy_imgs(t_game_data *data);
void	player_move(int p_x, int p_y, void *img, t_game_data *data);
void	put_images(int y, int x, char c, t_game_data *data);
int		close_game(t_game_data *data);

#endif