/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 11:09:48 by kkihn             #+#    #+#             */
/*   Updated: 2018/11/06 19:43:19 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

#include <stdio.h>

# define BUFF_SIZE 4096

int     ft_atoi(char *str);
int     count_digits(int d);
char	*ft_read_file(int fd);
char	*add_memory_concat_str(char *s1, char *s2);
int		ft_strlen(char *str);
int		check_width(char *str);
int		check_line_count(char *str);
int		check_first_line_and_symbols(char *str);
int     check_input_map(char *str);
int     **map_builder(char *str, int lines, int width, char obctacle);
void    print_array(int **array, int len, int width);
void	ft_finder(int **array, int len, int width);
char    return_params(char *str, char i);
#endif

