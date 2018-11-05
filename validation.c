/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 11:08:11 by kkihn             #+#    #+#             */
/*   Updated: 2018/11/05 13:51:03 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_read_map(int ret, int fd, char *buf)
{
	while ((ret = read(fd, buf, BUFF_SIZE)))
		buf[ret] = '\0';
	return (buf);
}

char	**ft_make_array(char *buf)
{


}

ft_validate(char *buf)
{
	int  

}

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	int		i;
	char	buf[BUFF_SIZE + 1];
	int		number_of_strings;
	char	obstacle;
	char	answer;
	number_of_strings = 0;
	ret = 0;
	i = 1;
	if (argc == 1)
		write(2, "map error\n", 10);
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
				buf = ft_read_map(ret, fd, buf);
				number_of_strings = atoi(buf);
				buff = buff + count_digits(number_of_strings);
				obstacle = buff;
				ft_validate(&buf);
						
			}
			close(fd);
			i++;
		}
	}
	return (0);
}
