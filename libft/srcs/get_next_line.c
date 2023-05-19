/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 04:05:55 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/19 15:51:52 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char *stock, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buf, stock);
	free(stock);
	return (temp);
}

static char	*clear_stock(char *stock)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	str = ft_calloc((ft_strlen(stock) - i) + 1, sizeof(char));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (stock && stock[i])
		str[j++] = stock[i++];
	free(stock);
	return (str);
}

static char	*get_line(const char *stock)
{
	int		i;
	char	*str;

	i = 0;
	if (!stock[i])
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
	{
		str[i] = stock[i];
		i++;
	}
	if (stock[i] && stock[i] == '\n' )
		str[i] = '\n';
	return (str);
}

static char	*read_file(int fd, char *stock, char *buf)
{
	int		read_nb;

	read_nb = 1;
	while (read_nb > 0)
	{
		read_nb = read(fd, buf, BUFFER_SIZE);
		if (read_nb == -1)
			return (NULL);
		if (!stock)
			stock = ft_calloc(1, 1);
		buf[read_nb] = 0;
		stock = ft_free(stock, buf);
		if (ft_strchr (buf, '\n'))
			break ;
	}
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stock[FD_SIZE];
	char		*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 65535)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	stock[fd] = read_file(fd, stock[fd], buf);
	free(buf);
	if (!stock[fd])
		return (NULL);
	line = get_line(stock[fd]);
	stock[fd] = clear_stock(stock[fd]);
	return (line);
}
/*
int	main(void)
{
	int	fd;
	char *line = NULL;
	int i = 0;
	fd = open("test", O_RDONLY);
	if (fd == -1)
	{
		printf("%s", "open() failed\n");
		return (-1);
	}
	while (i < 10)
	{
		printf("%s", "\n ///// \n");
		line = get_next_line(fd);
		printf("%s", line);
		i++;
	}
	if (close(fd) == -1)
	{
		printf("%s", "close() failed\n");
		return (-1);
	}
	return (0);
}
*/
