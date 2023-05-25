/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:19:59 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/25 19:21:02 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	images_init_monster(t_game_data *data)
{
	data->imgs.img_monster = mlx_xpm_file_to_image(data->mlx,
			"./tilesets/monster.xpm", &data->imgs.img_x, &data->imgs.img_y);
	data->imgs.img_monster1 = mlx_xpm_file_to_image(data->mlx,
			"./tilesets/monster1.xpm", &data->imgs.img_x, &data->imgs.img_y);
	data->imgs.img_monster2 = mlx_xpm_file_to_image(data->mlx,
			"./tilesets/monster2.xpm", &data->imgs.img_x, &data->imgs.img_y);
	data->imgs.img_monster3 = mlx_xpm_file_to_image(data->mlx,
			"./tilesets/monster3.xpm", &data->imgs.img_x, &data->imgs.img_y);

}

void	images_init(t_game_data *data)
{
	data->imgs.img_wall = mlx_xpm_file_to_image(data->mlx,
			"./tilesets/wall.xpm", &data->imgs.img_x, &data->imgs.img_y);
	data->imgs.img_floor = mlx_xpm_file_to_image(data->mlx,
			"./tilesets/floor.xpm", &data->imgs.img_x, &data->imgs.img_y);
	data->imgs.img_exit = mlx_xpm_file_to_image(data->mlx,
			"./tilesets/exit.xpm", &data->imgs.img_x, &data->imgs.img_y);
	data->imgs.img_player = mlx_xpm_file_to_image(data->mlx,
			"./tilesets/player.xpm", &data->imgs.img_x, &data->imgs.img_y);
	data->imgs.img_collec = mlx_xpm_file_to_image(data->mlx,
			"./tilesets/crys.xpm", &data->imgs.img_x, &data->imgs.img_y);
	data->imgs.img_collec1 = mlx_xpm_file_to_image(data->mlx,
			"./tilesets/crys1.xpm", &data->imgs.img_x, &data->imgs.img_y);
	data->imgs.img_collec2 = mlx_xpm_file_to_image(data->mlx,
			"./tilesets/crys2.xpm", &data->imgs.img_x, &data->imgs.img_y);
	data->imgs.img_collec3 = mlx_xpm_file_to_image(data->mlx,
			"./tilesets/crys3.xpm", &data->imgs.img_x, &data->imgs.img_y);
	data->imgs.img_player_d = mlx_xpm_file_to_image(data->mlx,
			"./tilesets/player_d.xpm", &data->imgs.img_x, &data->imgs.img_y);
	data->imgs.img_player_l = mlx_xpm_file_to_image(data->mlx,
			"./tilesets/player_l.xpm", &data->imgs.img_x, &data->imgs.img_y);
	data->imgs.img_player_r = mlx_xpm_file_to_image(data->mlx,
			"./tilesets/player_r.xpm", &data->imgs.img_x, &data->imgs.img_y);
	data->imgs.img_player_u = mlx_xpm_file_to_image(data->mlx,
			"./tilesets/player_u.xpm", &data->imgs.img_x, &data->imgs.img_y);
	images_init_monster(data);
}

void	put_images_from_map(int y, int x, t_game_data *data)
{
	if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs.img_wall, x * 64, y * 64);
	else if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs.img_floor, x * 64, y * 64);
	else if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs.img_collec, x * 64, y * 64);
	else if (data->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs.img_player, x * 64, y * 64);
	else if (data->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs.img_exit, x * 64, y * 64);
	else if (data->map[y][x] == 'M')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs.img_monster, x * 64, y * 64);
}

void	put_image(int y, int x, void *img, t_game_data *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, img, x * 64, y * 64);
}

void	put_images_from_data(t_game_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			put_images_from_map(y, x, data);
			x++;
		}
		y++;
	}
}
