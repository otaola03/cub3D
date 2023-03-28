/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:32:00 by jperez            #+#    #+#             */
/*   Updated: 2023/03/27 20:12:02 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

int	ft_round_number(double number)
{
	int	output;
	output = floor(number);
	if (output % 2 != 0)
		number--;
	return (output);
}
