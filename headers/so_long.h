/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:58:04 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/05/19 20:36:54 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../mlx/mlx.h"

typedef struct s_img_data
{

}			t_img_data;

typedef struct s_game_data
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
}			t_game_data;

void	error_message(char *str);
void	mapping(char **argv, t_game_data *data);
void	free_map(t_game_data *data);

#endif