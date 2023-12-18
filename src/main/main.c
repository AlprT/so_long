/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:13:57 by atangil           #+#    #+#             */
/*   Updated: 2023/12/08 18:29:25 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
#include "../lib/libft.h"
#include "../checks/checker.h"

int	main(int ac, char **av)
{
	if (ac == 2)
		so_long(is_valid(av[1]));
	else
		return (ft_putstr_fd("Error\nWrong Argument number", 1), -1);
	return (0);
}
