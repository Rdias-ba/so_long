/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:31:19 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/23 17:09:30 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static char	*addnum(char *buf, char temp_buf)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * ft_strlen(buf) + 2);
	if (!str)
		return (NULL);
	while (buf[i])
	{
		str[i] = buf[i];
		i++;
	}
	str[i] = temp_buf;
	str[++i] = '\0';
	free(buf);
	return (str);
}

static char	*get_map(int fd)
{
	int		res;
	int		map_c;
	char	*buf;
	char	temp;

	buf = ft_strdup("");
	res = read(fd, &temp, 1);
	map_c = res;
	while (res > 0)
	{
		buf = addnum(buf, temp);
		res = read(fd, &temp, 1);
		map_c++;
	}
	if (map_c <= 0)
	{
		free(buf);
		error_message("lecture non valide de la map");
		return (NULL);
	}
	return (buf);
}

static void	map_parsing(int fd, t_game_data *data)
{
	char	*map_line;

	map_line = get_map(fd);
	data->elems.exits = 0;
	data->elems.items = 0;
	data->elems.player = 0;
	data->map = ft_split(map_line, '\n');
	free(map_line);
	if (!data->map)
		return ;
	if (!check_walls(data))
		return (error_message_free(data, "la map n'est pas bien fermée"));
	if (!check_rectangle(data))
		return (error_message_free(data, "la map n'est pas rectangle"));
	if (!check_ingame(data))
		return (error_message_free(data, "la map intérieure n'est pas valide"));
	if (!check_playable(data))
		return (error_message_free(data, "la map ne peut pas être finie"));
}

void	mapping(char **argv, t_game_data *data)
{
	int	fd;

	data->map = NULL;
	if (!ft_strstr(argv[1], ".ber"))
		return (error_message("le fichier n'est pas en format .ber"));
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		return (error_message("le fichier n'a pas pue être lu"));
	map_parsing(fd, data);
	close(fd);
}
