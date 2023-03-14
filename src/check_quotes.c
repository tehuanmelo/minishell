/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:54:04 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/03/14 12:54:20 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int check_quotes(char *str)
{
    int double_flag;
    int single_flag;
    
    double_flag = 1;
    single_flag = 1;
    while (*str)
    {
        if (*str == DOUB_QUOT )
        {
            while (*str)
            {
                if (*str == DOUB_QUOT)
                    double_flag *= -1;
                str++;
            }
            if (double_flag == -1)
                return (1);
        }
        else if (*str == SING_QUOT )
        {
            while (*str)
            {
                if (*str == SING_QUOT)
                    single_flag *= -1;
                str++;
            }
            if (single_flag == -1)
                return (1);
        }
        str++;
    }
    return (0);
}