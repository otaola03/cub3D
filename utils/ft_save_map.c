/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:42:44 by jperez            #+#    #+#             */
/*   Updated: 2023/03/23 18:01:00 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

int	ft_cont_lines(char *addr)
{
	int		fd;
	int		cont;
	int		read_len;
	char	buff[2];

	fd = open(addr, O_RDONLY);
	if (fd <= 0)
	{
		perror("");
		return (1);
	}
	cont = 1;
	read_len = 1;
	while (read_len)
	{
		read_len = read(fd, buff, 1);
		buff[read_len] = '\0';
		if (buff[0] == '\n')
			cont++;
	}
	close(fd);
	return (cont);
}

char	**ft_save_map(char *map_addr)
{
	int		fd;
	int		i;
	int		map_len;
	char	*str;
	char	**map;

	fd = open(map_addr, O_RDONLY);
	map_len = ft_cont_lines(map_addr);
	if (map_len == 1)
		return (NULL);
	map = (char **)malloc(sizeof(char *) * (map_len + 1));
	if (!map)
		exit(-1);
	i = 0;
	str = ft_get_next_line(fd);
	map[i++] = str;
	while (str)
	{
		str = ft_get_next_line(fd);
		map[i++] = str;
	}
	if (map[i - 2][ft_strlen(map[i - 2]) - 1] == '\n')
		map_len--;
	close(fd);
	return (map);
}
