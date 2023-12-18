/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:12:00 by atangil           #+#    #+#             */
/*   Updated: 2023/12/18 17:41:56 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../lib/libft.h"

char	**is_valid(char *str)
{
	char	*map_path;
	char	**map;
	char	**map_cpy;

	if (!is_ber(str))
		return (ft_putstr_fd("Invalid file type\n", 1), exit(1), NULL);
	map_path = ft_strdup(str);
	if (!map_path)
		exit (1);
	create_map(map_path, &map, &map_cpy);
	if (!is_rectangle(map))
		return (free_map(map), free_map(map_cpy), exit(1), NULL);
	return (map);
}

// lines 18 - 20:
//		map_path is the path of the map
//		map
//		map_cpy

// lines 22 and 23:
//		checks the file extention

// lines 24 - 26:
// 		takes the map path from the argument and decelares as a
//			variable, then it checks if it is succsessfull or not.
