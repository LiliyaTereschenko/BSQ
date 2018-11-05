#include "header.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		i;
	i = 1;
//	if (argc == 1)
//		read map from input
//	else
//	{
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
              ft_read_file(int fd)// вернул строку
			}
			close(fd);
			i++;
		}
	}
	return (0);
}
