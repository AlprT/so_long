/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:10:36 by atangil           #+#    #+#             */
/*   Updated: 2023/12/08 15:52:27 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SPRITE_S 32
# define IMAGE_H 32

typedef struct s_data
{
	char	**map;
	void	*mlx;
	void	*mlx_win;
	void	*ch;
	void	*ch_left;
	void	*ch_right;
	void	*ch_up;
	void	*ch_down;
	void	*wall;
	void	*portal;
	void	*coin;
	void	*empt;
	int		ch_x;
	int		ch_y;
	int		mov;
	int		spd;
	int		mov_ct;
	int		coin_ct;
	int		map_h;
	int		map_w;
}	t_data;

void	so_long(char **map);
void	end(t_data *data);
void	put_img(t_data *data);
int		size_coin(char **map);
void	set_player(char **map, int *x, int *y);
void	set_tex(t_data *data);

//move
void	mov_up(t_data *data, int x, int y);
void	mov_lf(t_data *data, int x, int y);
void	mov_rg(t_data *data, int x, int y);
void	mov_dw(t_data *data, int x, int y);

#endif