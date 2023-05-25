/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:37:42 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/25 04:22:13 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	check_walls(t_game_data *data)
{
	int		i;
	int		j;
	size_t	map_w;

	i = 0;
	map_w = ft_strlen(data->map[i]) - 1;
	j = -1;
	while (data->map[i][++j])
		if (data->map[i][j] != '1')
			return (0);
	while (data->map[++i] && data->map[i + 1] != 0)
	{
		if (data->map[i][0] != '1' || data->map[i][map_w] != '1'
		|| data->map[i][map_w + 1] != '\0')
			return (0);
	}
	j = -1;
	while (data->map[i][++j])
		if (data->map[i][j] != '1')
			return (0);
	if (ft_strlen(data->map[i]) - 1 != map_w)
		return (0);
	return (1);
}

int	check_rectangle(t_game_data *data)
{
	data->map_y = 0;
	data->map_x = 0;
	while (data->map[data->map_y][data->map_x])
		data->map_x++;
	while (data->map[data->map_y] != 0)
		data->map_y++;
	if (data->map_y == data->map_x || data->map_y < 3 || data->map_x < 3)
		return (0);
	return (1);
}

void	get_elems(int y, int x, char c, t_game_data *data)
{
	if (c == 'P')
	{
		data->elems.player++;
		data->elems.p_x = x;
		data->elems.p_y = y;
	}
	if (c == 'E')
	{
		data->elems.exits++;
		data->elems.e_x = x;
		data->elems.e_y = y;
	}
}

int	check_ingame(t_game_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[++i] && data->map[i + 1] != 0)
	{
		j = 0;
		while (data->map[i][++j] && data->map[i][j + 1] != '\0')
		{
			if (data->map[i][j] == 'C')
				data->elems.items++;
			if (data->map[i][j] == 'P')
				get_elems(i, j, 'P', data);
			if (data->map[i][j] == 'E')
				get_elems(i, j, 'E', data);
			if (data->map[i][j] != '0' && data->map[i][j] != '1'
			&& data->map[i][j] != 'C' && data->map[i][j] != 'P'
			&& data->map[i][j] != 'E')
				return (0);
		}
	}
	if (data->elems.exits != 1 || data->elems.items < 1
		|| data->elems.player != 1)
		return (0);
	return (1);
}
