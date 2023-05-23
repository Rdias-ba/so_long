/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:17:49 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/23 20:05:00 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	close_game(t_game_data *data)
{
	free_map_data(data);
	destroy_imgs(data);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

void	open_game(t_game_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (error_message_free(data, "La fenêtre n'a pas pu s'ouvrir"));
	images_init(data);
	data->mlx_win = mlx_new_window(data->mlx, data->map_x * 64,
			data->map_y * 64, "so_long");
	put_images_from_data(data);
	mlx_hook(data->mlx_win, 17, 0, &close_game, data);
	mlx_loop(data->mlx);
}
