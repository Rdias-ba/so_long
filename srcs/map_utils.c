/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:31:19 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/19 20:34:52 by rdias-ba         ###   ########.fr       */
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
	ft_printf("%s", buf);
	return (buf);
}

static void	map_parsing(int fd, t_game_data *data)
{
	data->map = ft_split(get_map(fd), '\n');
	if (!check_rectangle(data))
		return (free_map(data));
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
}

