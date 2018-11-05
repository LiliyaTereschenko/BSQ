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
check_input_map(char *str)
{

}

int check_width(*str)
{
    int width;
    int width_counter;
    while (*str != '\n')
        str++;
    str++;
    while (*str != '\n')
    {
        width++;
        str++;
    }
    str++;
    while (*str != '\0')
    {
        while (*str != '\n')
        {
            width_counter++;
            str++;
        }
        if (width != width_counter)
            return (0);
        str++;
    }

}

int check_line_count(*str)
{
    int line_counter;
    int lines;

    line_counter = 0;
    lines = ft_atoi(str);
    while (*str != '\n')
        str++;
    str++;
    while (*str != '\0')
    {
        if (*str == '\n')
            line_counter++;
        str++;
    }
    if (lines != line_counter)
        return (0);
    else
        return (1);
}

int check_first_line(*str)
{
    if (ft_atoi(str) <= 0)
        return (0);
    else
        str = str + count_digits(ft_atoi(str));
    if (*str != '.')
        return (0);
    else
        str++;
    if (!(((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')) &&
        ((*(str++) >= 'a' && *(str++) <= 'z') || (*(str++) >= 'A' && *(str++) <= 'Z')) &&
            (*(str+2) == '\n')))
            return (0);
    //str = str + 3;
    return (1);
}
