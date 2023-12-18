/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:11:35 by atangil           #+#    #+#             */
/*   Updated: 2023/12/18 17:42:28 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>

char	**is_valid(char *str);
int		is_ber(char *str);
void	free_map(char **map);
void	create_map(char *map_path, char ***map1, char ***map2);
void	find_size(char **map, int *width, int *height);
int		is_rectangle(char **map);

#endif