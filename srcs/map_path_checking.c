/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_checking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:31:18 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/25 19:28:00 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static char	**empty_grid(t_game_data *data)
{
	int		i;
	char	**empty_map;

	i = 0;
	empty_map = malloc(sizeof(char *) * (data->map_y + 1));
	if (!empty_map)
		return (NULL);
	empty_map[data->map_y] = 0;
	while (data->map[i])
	{
		empty_map[i] = ft_strdup(data->map[i]);
		i++;
	}
	return (empty_map);
}

static int	filling(int x, int y, char **temp_map, t_game_data *data)
{
	static int	collectibles = 0;
	static int	exit = 0;

	if (x < 0 || y < 0 || x >= data->map_x || y >= data->map_y)
		return (0);
	if (temp_map[y][x] == 'X' || temp_map[y][x] == '1' || temp_map[y][x] == 'M')
		return (0);
	else if (temp_map[y][x] == 'C')
		collectibles++;
	else if (temp_map[y][x] == 'E')
		exit++;
	temp_map[y][x] = 'X';
	filling(x - 1, y, temp_map, data);
	filling(x + 1, y, temp_map, data);
	filling(x, y - 1, temp_map, data);
	filling(x, y + 1, temp_map, data);
	if (collectibles != data->elems.items || !exit)
		return (0);
	return (1);
}

int	check_playable(t_game_data *data)
{
	char	**temp_map;

	temp_map = empty_grid(data);
	if (!temp_map)
		return (0);
	if (!filling(data->elems.p_x, data->elems.p_y, temp_map, data))
	{
		free_map(temp_map);
		return (0);
	}
	free_map(temp_map);
	return (1);
}
