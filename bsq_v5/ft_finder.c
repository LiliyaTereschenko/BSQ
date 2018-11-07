/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:39:46 by kkihn             #+#    #+#             */
/*   Updated: 2018/11/07 15:53:57 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void 	ft_finder(int **arr, int len, int width, char *str)
{
	int j;
	int i;
	int min;
	int I;
	int J;
	
	min = 0;
	I = 0;
	J = 0;
	i = len - 1;
	while (i >= 0)
	{       
		j = width - 1;
		while (j >= 0)
		{	if (arr[i][j] != 0)
			{
				min = arr[i][j + 1];
				if (arr[i + 1][j] < min)
					min = arr[i + 1][j];
				if (arr[i + 1][j + 1] < min)
					min = arr[i + 1][j + 1];
				arr[i][j] = min + arr[i][j];
            	if (arr[i][j] >= arr[I][J])
            	{
            		I = i;
                	J = j;
            	}
            }
			j--;
		}
		i--;
	}
	print_solution(str, arr[I][J], I, J);
}

void    print_solution(char *str, int size, int I, int  J)
{
	int		i;
	int		j;
	char	full;

	i = 0;
	j = 0;
	full = return_params(str, 'f');
	while (*str != '\n')
		str++;
	str++;
	while (*str != '\0')
	{

		if (i >= I && i <= I + size - 1 && j >= J && j <= J + size - 1)
		{	
			write(1, &full, 1);
		}
		else
			write(1, &(*str), 1);
		if (*str == '\n')
		{
			i++;
			j = -1;
		}
		str++;
		j++;
	}
}
