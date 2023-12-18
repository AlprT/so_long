/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:33:52 by atangil           #+#    #+#             */
/*   Updated: 2023/12/18 18:04:35 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
#include "../lib/libft.h"

void	mov_up(t_data *data, int x, int y)
{
	if (data -> map[x - 1][y] == 'E' && data -> coin_ct == 0)
		end(data);
	else if (data -> map[x - 1][y] == 'E')
		return ;
	if (data -> map[x - 1][y] != '1')
	{
		if (data -> map[x - 1][y] == 'C')
			data -> coin_ct--;
		data -> ch = data -> ch_up;
		data -> mov_ct++;
		ft_putstr_fd("Step : ", 1);
		ft_putnbr_fd(data -> mov_ct, 1);
		ft_putchar_fd('\n', 1);
		data -> map[x][y] = '0';
		data -> map[x - 1][y] = 'P';
		data -> ch_x--;
	}
}

void	mov_dw(t_data *data, int x, int y)
{
	if (data -> map[x + 1][y] == 'E' && data -> coin_ct == 0)
		end(data);
	else if (data -> map[x + 1][y] == 'E')
		return ;
	if (data -> map[x + 1][y] != '1')
	{
		if (data -> map[x + 1][y] == 'C')
			data -> coin_ct--;
		data -> ch = data -> ch_down;
		data -> mov_ct++;
		ft_putstr_fd("Step : ", 1);
		ft_putnbr_fd(data -> mov_ct, 1);
		ft_putchar_fd('\n', 1);
		data -> map[x][y] = '0';
		data -> map[x + 1][y] = 'P';
		data -> ch_x++;
	}
}

void	mov_lf(t_data *data, int x, int y)
{
	if (data -> map[x][y - 1] == 'E' && data -> coin_ct == 0)
		end(data);
	else if (data -> map[x][y - 1] == 'E')
		return ;
	if (data -> map[x][y - 1] != '1')
	{
		if (data -> map[x][y - 1] == 'C')
			data -> coin_ct--;
		data -> ch = data -> ch_left;
		data -> mov_ct++;
		ft_putstr_fd("Step : ", 1);
		ft_putnbr_fd(data -> mov_ct, 1);
		ft_putchar_fd('\n', 1);
		data -> map[x][y] = '0';
		data -> map[x][y - 1] = 'P';
		data -> ch_y--;
	}
}

void	mov_rg(t_data *data, int x, int y)
{
	if (data -> map[x][y + 1] == 'E' && data -> coin_ct == 0)
		end(data);
	else if (data -> map[x][y + 1] == 'E')
		return ;
	if (data -> map[x][y + 1] != '1')
	{
		if (data -> map[x][y + 1] == 'C')
			data -> coin_ct--;
		data -> ch = data -> ch_right;
		data -> mov_ct++;
		ft_putstr_fd("Step : ", 1);
		ft_putnbr_fd(data -> mov_ct, 1);
		ft_putchar_fd('\n', 1);
		data -> map[x][y] = '0';
		data -> map[x][y + 1] = 'P';
		data -> ch_y++;
	}
}

