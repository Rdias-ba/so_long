/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:39:38 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/25 19:32:29 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	player_move(int p_x, int p_y, void *img, t_game_data *data)
{
	if (data->map[p_y][p_x] == 'C' )
		data->c_found++;
	else if (data->map[p_y][p_x] == 'E' && data->c_found != data->elems.items)
		return ;
	else if (data->map[p_y][p_x] == 'E')
		data->e_found++;
	else if (data->map[p_y][p_x] == 'M')
	{
		ft_printf("Vous êtes mort!!");
		close_game(data);
	}
	data->steps++;
	data->map[data->elems.p_y][data->elems.p_x] = '0';
	put_image(data->elems.p_y, data->elems.p_x, data->imgs.img_floor, data);
	data->map[p_y][p_x] = 'P';
	put_image(p_y, p_x, img, data);
	data->elems.p_x = p_x;
	data->elems.p_y = p_y;
	display_steps(data);
	if (data->c_found == data->elems.items
		&& data->e_found == data->elems.exits)
	{
		ft_printf("Victoire en %d pas!!", data->steps);
		close_game(data);
	}
}
