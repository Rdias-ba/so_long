/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:19:59 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/25 04:06:58 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	destroy_imgs(t_game_data *data)
{
	mlx_destroy_image(data->mlx, data->imgs.img_wall);
	mlx_destroy_image(data->mlx, data->imgs.img_floor);
	mlx_destroy_image(data->mlx, data->imgs.img_player);
	mlx_destroy_image(data->mlx, data->imgs.img_player_u);
	mlx_destroy_image(data->mlx, data->imgs.img_player_r);
	mlx_destroy_image(data->mlx, data->imgs.img_player_l);
	mlx_destroy_image(data->mlx, data->imgs.img_player_d);
	mlx_destroy_image(data->mlx, data->imgs.img_collectible);
	mlx_destroy_image(data->mlx, data->imgs.img_exit);
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
	data->imgs.img_collectible = mlx_xpm_file_to_image(data->mlx,
			"./tilesets/collectible.xpm", &data->imgs.img_x, &data->imgs.img_y);
	data->imgs.img_player_d = mlx_xpm_file_to_image(data->mlx,
			"./tilesets/player_d.xpm", &data->imgs.img_x, &data->imgs.img_y);
	data->imgs.img_player_l = mlx_xpm_file_to_image(data->mlx,
			"./tilesets/player_l.xpm", &data->imgs.img_x, &data->imgs.img_y);
	data->imgs.img_player_r = mlx_xpm_file_to_image(data->mlx,
			"./tilesets/player_r.xpm", &data->imgs.img_x, &data->imgs.img_y);
	data->imgs.img_player_u = mlx_xpm_file_to_image(data->mlx,
			"./tilesets/player_u.xpm", &data->imgs.img_x, &data->imgs.img_y);
}

void	put_images(int y, int x, char c, t_game_data *data)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs.img_wall, x * 64, y * 64);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs.img_floor, x * 64, y * 64);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs.img_collectible, x * 64, y * 64);
	else if (c == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs.img_player, x * 64, y * 64);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs.img_exit, x * 64, y * 64);
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
			put_images(y, x, data->map[y][x], data);
			x++;
		}
		y++;
	}
}
