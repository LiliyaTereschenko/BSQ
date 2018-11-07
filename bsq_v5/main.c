/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:55:02 by kkihn             #+#    #+#             */
/*   Updated: 2018/11/07 16:47:09 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	read_map_from_input(void)
{
	char	*str;
	int     **map;

	str = ft_read_file(0);
	if (*str && check_input_map(str))
	{
		map = map_builder(str, check_line_count(str), check_width(str),
				return_params(str, 'o'));
		ft_finder(map, check_line_count(str), check_width(str), str);
	}
	else
		write(2, "map error\n", 10);

}

int		main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*str;
	int 	**map;

	i = 1;
	if (argc <= 1)
		read_map_from_input();
	else
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd == -1)
			{
				write(2, "map error\n", 10);
				return (0);
			}
			if (fd)
			{
            	str = ft_read_file(fd);
				if (check_input_map(str) == 0)
				{
					write(2, "map error\n", 10);
					return (0);
				}
				else
				{
					map = map_builder(str, check_line_count(str),
							check_width(str), return_params(str, 'o'));
					ft_finder(map, check_line_count(str), check_width(str), str);
				}
			}
			close(fd);
			i++;
		}
	}
	return (0);
}
