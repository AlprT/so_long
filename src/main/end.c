/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:20:45 by atangil           #+#    #+#             */
/*   Updated: 2023/12/18 18:09:22 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../checks/checker.h"
#include "../../inc/so_long.h"
#include <stdlib.h>

void	end(t_data *data)
{
	if (!!data -> map)
		free_map(data -> map);
	if (!!data -> ch_up)
		mlx_destroy_image(data -> mlx, data -> ch_up);
	if (!!data -> ch_down)
		mlx_destroy_image(data -> mlx, data -> ch_down);
	if (!!data -> ch_right)
		mlx_destroy_image(data -> mlx, data -> ch_right);
	if (!!data -> ch_left)
		mlx_destroy_image(data -> mlx, data -> ch_left);
	if (!!data -> wall)
		mlx_destroy_image(data -> mlx, data -> wall);
	if (!!data -> empt)
		mlx_destroy_image(data -> mlx, data -> empt);
	if (!!data -> coin)
		mlx_destroy_image(data -> mlx, data -> coin);
	if (!!data -> wall)
		mlx_destroy_image(data -> mlx, data -> wall);
	if (!!data -> portal)
		mlx_destroy_image(data -> mlx, data -> portal);
	if (!!data -> mlx_win)
		mlx_destroy_window(data -> mlx, data -> mlx_win);
	if (!!data)
		free(data);
	exit (0);
}
