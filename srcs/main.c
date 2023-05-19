/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:25:39 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/19 17:36:28 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	main(int argc, char **argv)
{
	t_game_data	data;

	if (argc != 2)
	{
		error_message("Un seul argument .bet requis");
		return (0);
	}
	mapping(argv, &data);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 1200, 800, "Salut!");
	mlx_mouse_show(data.mlx, data.mlx_win);
	mlx_loop(data.mlx);
	return (0);
}
