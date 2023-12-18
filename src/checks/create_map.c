/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:30:35 by atangil           #+#    #+#             */
/*   Updated: 2023/12/18 18:11:22 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "../lib/libft.h"
#include "checker.h"

static void	quit(int fd, char *line, char *map_path)
{
	free(map_path);
	if (line)
		free (line);
	close (fd);
	ft_putstr_fd("Error\n", 1);
	exit (1);
}

// its a function to help us to abort proccess,
// it first frees map_path, then frees the mapline if it exists
// then closes the file and exits with a error message 

static char	*read_map(char *map_path)
{
	int		fd;
	int		i;
	char	line[17];
	char	*join;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("File unreadable ", 1), NULL);
	i = read(fd, line, 16);
	line[i] = '\0';
	join = NULL;
	while (i)
	{
		join = ft_strjoin(join, line);
		if (!join)
			quit(fd, line, map_path);
		i = read(fd, line, 16);
		line[i] = '\0';
	}
	return (free(map_path), close(fd), join);
}

// size of line is 22 but one line of map is 20 why?
//		because when we read we also read '\n's also there is null-terminator
// in the end.

// why do we read 21 chars instead of 20?
//		because we read newlines too.

// that function reads the map tiles from our map file
// then returns it in one string divided by newlines
// by joining one line by one line to our return string

void	create_map(char *map_path, char ***map1, char ***map2)
{
	char	*map_line;

	map_line = read_map(map_path);
	if (!map_line)
		return (ft_putstr_fd("Error\n", 1), exit(1));
	*map1 = ft_split(map_line, '\n');
	if (!(*map1))
		return (free(map_line), ft_putstr_fd("Error\n", 1), exit(1));
	*map2 = ft_split(map_line, '\n');
	if (!(*map2))
		return (free(map_line), free_map(*map1), ft_putstr_fd("Error\n", 1) \
				, exit(1));
	free (map_line);
}

// creates 2 maps according to file at the path we gave to function as parameter
// read_map function reads the file and returns the lines in the file
// then we split our line with '\n' delimeter and use that 2 dimensional array
// as our map tiles.
