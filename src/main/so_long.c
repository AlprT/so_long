/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:11:58 by atangil           #+#    #+#             */
/*   Updated: 2023/12/08 18:37:14 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../checks/checker.h"
#include "../../inc/so_long.h"
#include <stdlib.h>
#include <stdio.h>

int	key_dw(int keycode, t_data *data)
{
	if (keycode == 53)
		end(data);
	data -> mov = keycode;
	return (0);
}

int	key_up(int keycode, t_data *data)
{
	(void)keycode;
	data -> mov = -1;
	return (0);
}

int close_game(t_data *data)
{
	end(data);
	return (0);
}

int	render_frame(t_data *data)
{
	int	x;
	int	y;

	if (data -> spd != 800)
	{
		data -> spd++;
		return (0);
	}
	x = data -> ch_x;
	y = data -> ch_y;
	if (data -> mov == 2)
		mov_rg(data, x, y);
	else if (data -> mov == 0)
		mov_lf(data, x, y);
	else if (data -> mov == 1)
		mov_dw(data, x, y);
	else if (data -> mov == 13)
		mov_up(data, x, y);
	data -> spd = 0;
	mlx_clear_window(data -> mlx, data -> mlx_win);
	put_img(data);
	return (0);
}

void	so_long(char **map)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (free_map(map), exit(1));
	data -> map = map;
	find_size(map, &data -> map_w, &data -> map_h);
	data -> coin_ct = size_coin(map);
	set_player(map, &data -> ch_x, &data -> ch_y);
	data -> mlx = mlx_init();
	if (!data -> mlx)
		return (free_map(map), exit(1));
	data -> mlx_win = mlx_new_window(data -> mlx, SPRITE_S * data -> map_w, \
		SPRITE_S * data -> map_h, "Pac-dude");
	if (!data -> mlx_win)
		return (free_map(map), free(data));
	data -> spd = 0;
	data -> mov_ct = 0;
	data -> mov = -1;
	set_tex(data);
	mlx_hook(data -> mlx_win, 02, (1L << 0), key_dw, data);
	mlx_hook(data -> mlx_win, 03, (1L << 1), key_up, data);
	mlx_hook(data -> mlx_win, 17, 0, close_game, data);
	mlx_loop_hook(data -> mlx, render_frame, data);
	mlx_loop(data -> mlx);
}
