/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:45:30 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/06/27 16:50:04 by rdias-ba         ###   ########.fr       */
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
	mlx_destroy_image(data->mlx, data->imgs.img_collec);
	mlx_destroy_image(data->mlx, data->imgs.img_collec1);
	mlx_destroy_image(data->mlx, data->imgs.img_collec2);
	mlx_destroy_image(data->mlx, data->imgs.img_collec3);
	mlx_destroy_image(data->mlx, data->imgs.img_monster1);
	mlx_destroy_image(data->mlx, data->imgs.img_monster2);
	mlx_destroy_image(data->mlx, data->imgs.img_monster3);
	mlx_destroy_image(data->mlx, data->imgs.img_monster);
	mlx_destroy_image(data->mlx, data->imgs.img_exit);
}

static void	*anim_collec(t_game_data *data)
{
	if (data->imgs.img_loop == 2)
		return (data->imgs.img_collec1);
	else if (data->imgs.img_loop == 3)
		return (data->imgs.img_collec2);
	else if (data->imgs.img_loop == 4)
		return (data->imgs.img_collec3);
	else if (data->imgs.img_loop == 5)
		return (data->imgs.img_collec2);
	else if (data->imgs.img_loop == 6)
		return (data->imgs.img_collec1);
	return (data->imgs.img_collec);
}

static void	*anim_monster(t_game_data *data)
{
	if (data->imgs.img_loop == 2)
		return (data->imgs.img_monster1);
	else if (data->imgs.img_loop == 3)
		return (data->imgs.img_monster2);
	else if (data->imgs.img_loop == 4)
		return (data->imgs.img_monster3);
	else if (data->imgs.img_loop == 5)
		return (data->imgs.img_monster2);
	else if (data->imgs.img_loop == 6)
		return (data->imgs.img_monster1);
	return (data->imgs.img_monster);
}

int	anim(t_game_data *data)
{
	int	y;
	int	x;

	data->loop_timer++;
	if (data->loop_timer < LOOP_RATE)
		return (0);
	data->loop_timer = 0;
	data->imgs.img_loop++;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'C')
				put_image(y, x, anim_collec(data), data);
			if (data->map[y][x] == 'M')
				put_image(y, x, anim_monster(data), data);
			x++;
		}
		y++;
	}
	if (data->imgs.img_loop == 6)
		data->imgs.img_loop = 0;
	return (0);
}
