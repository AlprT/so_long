/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:01:42 by atangil           #+#    #+#             */
/*   Updated: 2023/12/08 15:19:03 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../../inc/so_long.h"
#include "../lib/libft.h"

void	set_tex(t_data *data)
{
	int	i;
	int	j;

	data -> ch_up = mlx_xpm_file_to_image(data -> mlx,
			"./src/Sprites/Pac-Man/pac_semi_up.xpm", &i, &j);
	data -> ch_down = mlx_xpm_file_to_image(data -> mlx,
			"./src/Sprites/Pac-Man/pac_semi_down.xpm", &i, &j);
	data -> ch_right = mlx_xpm_file_to_image(data -> mlx,
			"./src/Sprites/Pac-Man/pac_semi_right.xpm", &i, &j);
	data -> ch_left = mlx_xpm_file_to_image(data -> mlx,
			"./src/Sprites/Pac-Man/pac_semi_left.xpm", &i, &j);
	data -> wall = mlx_xpm_file_to_image(data -> mlx,
			"./src/Sprites/Other/Walls/wall.xpm", &i, &j);
	data -> portal = mlx_xpm_file_to_image(data -> mlx,
			"./src/Sprites/Other/Portal/portal.xpm", &i, &j);
	data -> coin = mlx_xpm_file_to_image(data -> mlx,
			"./src/Sprites/Other/Pacdots/pacdot_food.xpm", &i, &j);
	data -> empt = mlx_xpm_file_to_image(data -> mlx,
			"./src/Sprites/Other/Walls/black.xpm", &i, &j);
	if (!data -> ch_up || !data -> ch_down || !data -> ch_right
		|| !data -> ch_left || !data -> wall || !data -> portal
		|| !data -> coin || !data -> empt)
		return (ft_putstr_fd("issues about xpm files\n", 1), end(data));
	data -> ch = data -> ch_right;
}
