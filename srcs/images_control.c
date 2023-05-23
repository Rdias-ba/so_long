/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:19:59 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/23 20:04:48 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	destroy_imgs(t_game_data *data)
{
	mlx_destroy_image(data->mlx, data->imgs.img_wall);
	mlx_destroy_image(data->mlx, data->imgs.img_wall_back);
}

void	images_init(t_game_data *data)
{
	data->imgs.img_wall = mlx_xpm_file_to_image(data->mlx,
			"./tilesets/walls.xpm", &data->imgs.img_x, &data->imgs.img_y);
	data->imgs.img_wall_back = mlx_xpm_file_to_image(data->mlx,
			"./tilesets/back_walls.xpm", &data->imgs.img_x, &data->imgs.img_y);
}

static void	put_images(int y, int x, char c, t_game_data *data)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs.img_wall, x * 64, y * 64);
	if (c != '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs.img_wall_back, x * 64, y * 64);
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
