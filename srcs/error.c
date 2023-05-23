/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:09:41 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/23 16:34:00 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	error_message(char *str)
{
	ft_printf("Error\n");
	ft_printf("%s", str);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	free_map_data(t_game_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
}

void	error_message_free(t_game_data *data, char *str)
{
	ft_printf("Error\n");
	ft_printf("%s", str);
	free_map_data(data);
}
