/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:29:22 by kkihn             #+#    #+#             */
/*   Updated: 2018/11/07 15:02:42 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	read_map_from_input(void)
{
	char	*str;
	int     **map;

	str = ft_read_file(0);
	printf("str = %s\n", str);
	str[ft_strlen(str) - 1] = '\0';
 printf("str = %s\n", str);
	if (*str && check_input_map(str) == 0)
	{
		map = map_builder(str, check_line_count(str), check_width(str), return_params(str, 'o'));
		ft_finder(map, check_line_count(str), check_width(str), str);
		print_array(map, check_line_count(str) + 1, check_width(str) + 1);
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
				//	printf("str =\n%s\n", str);	
					printf("line count = %d\n", check_line_count(str));
					printf("width = %d\n", check_width(str));
					map = map_builder(str, check_line_count(str), check_width(str), return_params(str, 'o'));
				//	print_array(map, check_line_count(str) + 1, check_width(str) + 1);
				//	printf("\n");
			//		map_builder(str, check_line_count(str), check_width(str));
					ft_finder(map, check_line_count(str), check_width(str), str);
					print_array(map, check_line_count(str) + 1, check_width(str) + 1);
				}
			}
			close(fd);
			i++;
		}
	}
	return (0);
}
