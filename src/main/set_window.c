/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:06:27 by atangil           #+#    #+#             */
/*   Updated: 2023/12/07 18:32:46 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../../inc/so_long.h"

void	put_img_sub(t_data *data, void *img, int i, int j)
{
	mlx_put_image_to_window(data -> mlx, data -> mlx_win, img,
		j * SPRITE_S, i * SPRITE_S);
}
// this function just calls an mlx function that can put images into the window.
// we give the function, mlx, the pointer to the mlx window, the image itself
//		and the coordinations of where its gonna put image.
// we multiply coordinates with SPRITE_S (which is 32 atm) because funcion puts
// images using PIXEL coordinates, so with that multiplication we split the map
// by squares with 32 width and height.

void	put_img(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data -> map[i])
	{
		j = 0;
		while (data -> map[i][j])
		{
			if (data -> map[i][j] == '1')
				put_img_sub(data, data -> wall, i, j);
			if (data -> map[i][j] == '0')
				put_img_sub(data, data -> empt, i, j);
			if (data -> map[i][j] == 'P')
				put_img_sub(data, data -> ch, i, j);
			if (data -> map[i][j] == 'E')
				put_img_sub(data, data -> portal, i, j);
			if (data -> map[i][j] == 'C')
				put_img_sub(data, data -> coin, i, j);
			j++;
		}
		i++;
	}
}
