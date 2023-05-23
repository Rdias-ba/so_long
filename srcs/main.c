/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:25:39 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/23 20:02:24 by rdias-ba         ###   ########.fr       */
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
	if (data.map == NULL)
		return (0);
	open_game(&data);
	return (0);
}
