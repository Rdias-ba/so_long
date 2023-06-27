/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:17:49 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/06/27 17:03:17 by rdias-ba         ###   ########.fr       */
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

void	display_steps(t_game_data *data)
{
	char	*str;

	str = ft_itoa(data->steps);
	put_image(0, 0, data->imgs.img_wall, data);
	put_image(0, 1, data->imgs.img_wall, data);
	mlx_string_put(data->mlx, data->mlx_win, 20, 13, 0x000000, "MOVES: ");
	mlx_string_put(data->mlx, data->mlx_win, 55, 13, 0x000000, str);
	free(str);
}

static int	key_press(int key, t_game_data *data)
{
	int	p_x;
	int	p_y;

	p_x = data->elems.p_x;
	p_y = data->elems.p_y;
	if (key == KEY_ESC)
		close_game(data);
	if ((key == KEY_A || key == KEY_LEFT) && data->map[p_y][p_x - 1] != '1')
		player_move(p_x - 1, p_y, data->imgs.img_player_l, data);
	if ((key == KEY_S || key == KEY_DOWN) && data->map[p_y + 1][p_x] != '1')
		player_move(p_x, p_y + 1, data->imgs.img_player_d, data);
	if ((key == KEY_D || key == KEY_RIGHT) && data->map[p_y][p_x + 1] != '1')
		player_move(p_x + 1, p_y, data->imgs.img_player_r, data);
	if ((key == KEY_W || key == KEY_UP) && data->map[p_y - 1][p_x] != '1')
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
	data->loop_timer = 0;
	data->imgs.img_loop = 1;
	images_init(data);
	data->mlx_win = mlx_new_window(data->mlx, data->map_x * TEXTURE_RES,
			data->map_y * TEXTURE_RES, "so_long");
	put_images_from_data(data);
	display_steps(data);
	mlx_hook(data->mlx_win, 17, 0, &close_game, data);
	mlx_hook(data->mlx_win, 2, (1L << 0), &key_press, data);
	mlx_loop_hook(data->mlx, &anim, data);
	mlx_loop(data->mlx);
}
