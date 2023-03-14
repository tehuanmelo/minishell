/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:26:41 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/03/14 12:54:45 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char get_delimiter(char *str)
{
    char delimiter;

    if (*str == DOUB_QUOT)
        delimiter = DOUB_QUOT;
    else if (*str == SING_QUOT)
        delimiter = SING_QUOT;
    else
        delimiter = SPACE;
    return (delimiter);
}

size_t ft_token_count(char *str)
{
    char *deli;
    size_t counter;
    char delimiter;

    counter = 0;
    while (str)
    {
        while (*str == SPACE)
            str++;
        delimiter = get_delimiter(str);
        if (delimiter == DOUB_QUOT || delimiter == SING_QUOT)
            str++;
        deli = strchr(str, delimiter);
        if (deli)
        {
            counter++;
            str = deli + 1;
        }
        else
            break;
    }
    if (ft_strlen(str) > 0)
        counter++;
    return (counter);
}

char **get_tokens(char *str)
{
    char delimiter;
    char *input;
    char **tokens;
    size_t i;
    size_t len;
    size_t tokens_len;

    tokens_len = ft_token_count(str);
    tokens = malloc(sizeof(char *) * ft_token_count(str) + 1);
    if (!tokens)
        return (NULL);
    i = -1;
    while (++i < tokens_len)
    {
        while (*str == SPACE)
            str++;
        delimiter = get_delimiter(str);
        if (delimiter == DOUB_QUOT || delimiter == SING_QUOT)
            str++;
        input = str;
        len = 0;
        while (*str && *str != delimiter)
        {
            str++;
            len++;
        }
        if (delimiter == DOUB_QUOT || delimiter == SING_QUOT)
            str++;
        tokens[i] = ft_substr(input, 0, len);
    }
    tokens[i] = 0;
    return (tokens);
}
