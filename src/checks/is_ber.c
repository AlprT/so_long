/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ber.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:17:54 by atangil           #+#    #+#             */
/*   Updated: 2023/11/21 18:27:46 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

// it checks if the file extention is valid or not. by searching ".ber"
//		in last 4 characters.
// it should have .ber as file extention, otherwise its invalid.

int	is_ber(char *str)
{
	return (!ft_strncmp(str + ft_strlen(str) - 4, ".ber", 5));
}
