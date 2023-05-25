/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:17:49 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/25 03:21:05 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	close_game(t_game_data *data)
{
	free_map_data(data);
	destroy_imgs(data);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

static int	screen_size(t_game_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_get_screen_size(data->mlx, &x, &y);
	if (x < data->map_x * 64 || y < data->map_y * 64)
	{
		destroy_imgs(data);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (0);
	}
	return (1);
}

static int	key_press(int key, t_game_data *data)
{
	int	p_x;
	int	p_y;

	p_x = data->elems.p_x;
	p_y = data->elems.p_y;
	if (key == KEY_ESC)
		close_game(data);
	if (key == KEY_A && data->map[p_y][p_x - 1] != '1')
		player_move(p_x - 1, p_y, data->imgs.img_player_l, data);
	if (key == KEY_S && data->map[p_y + 1][p_x] != '1')
		player_move(p_x, p_y + 1, data->imgs.img_player_d, data);
	if (key == KEY_D && data->map[p_y][p_x + 1] != '1')
		player_move(p_x + 1, p_y, data->imgs.img_player_r, data);
	if (key == KEY_W && data->map[p_y - 1][p_x] != '1')
		player_move(p_x, p_y - 1, data->imgs.img_player_u, data);
	return (0);
}

void	open_game(t_game_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (error_message_free(data, "La fenêtre n'a pas pu s'ouvrir"));
	data->c_found = 0;
	data->e_found = 0;
	data->steps = 0;
	images_init(data);
	if (!screen_size(data))
		return (error_message_free(data, "La map est trop grande"));
	data->mlx_win = mlx_new_window(data->mlx, data->map_x * 64,
			data->map_y * 64, "so_long");
	put_images_from_data(data);
	mlx_hook(data->mlx_win, 17, 0, &close_game, data);
	mlx_hook(data->mlx_win, 2, (1L << 0), &key_press, data);
	mlx_loop(data->mlx);
}
