/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:01:40 by atangil           #+#    #+#             */
/*   Updated: 2023/12/08 15:50:50 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	find_size(char **map, int *width, int *height)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[0][x])
		x++;
	while (map[y])
		y++;
	*width = x;
	*height = y;
}

// finds width and height values of the map

static int	check_tile(char tile, int is_last)
{
	static int	start = 0;
	static int	coins = 0;
	static int	exit = 0;

	if (tile == 'P')
		start++;
	else if (tile == 'C')
		coins++;
	else if (tile == 'E')
		exit++;
	if (is_last)
	{
		if (start != 1 || coins < 1 || exit != 1)
			return (0);
		return (1);
	}
	return (2);
}

// checks the type of the given tile, there should be 1 exit 1 start point
// and at least 1 coin in the map. Function counts these tiles and stores it
// as static variables.
// at the end when we gave 1 as is_last value, it controls number of each tile
// type and returns 1 or 0 according to result of that control

int	is_rectangle(char **map)
{
	int	width;
	int	height;
	int	i;
	int	j;

	find_size(map, &width, &height);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if ((!i || i == height || !j || j == width) && map[i][j] != '1')
				return (ft_putstr_fd("Map error\nMissing wall tile", 1), 0);
			if (map[i][j] == 'P' || map[i][j] == 'C' || map[i][j] == 'E')
				check_tile(map[i][j], 0);
			else if (map[i][j] != '1' && map[i][j] != '0')
				return (ft_putstr_fd("Map error\nInvalid tile", 1), 0);
		}
		if (width != j)
			return (ft_putstr_fd("Map error\nNot rectangular", 1), 0);
	}
	if (!check_tile('x', 1))
		return (ft_putstr_fd("Map error\nNot enough tiles", 1), 0);
	return (1);
}

// function checks tiles of the map and checks if it is a rectangle or not
// first it takes width and height of the map, then it starts a loop
// that iterates through all members of the map

// then it checks if is map covered by wall tiles,

//...............
//...........
