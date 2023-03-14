/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:26:41 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/03/14 13:17:53 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// Generic function just to print the output of split function
void print_token(t_input *token)
{
    printf("\nstring --> %s\n\n", token->input);
    printf("tokens\n");
    printf("---------\n");
    while (*(token)->tokens)
    {
        printf("::%s::\n", *(token)->tokens);
        token->tokens++;
    }
    printf("---------\n\n");
}

int main()
{
    char *user_input;
    
    // Structure to get the user input and prepare the tokens
    t_input input_struct;

    // Initialize Readline
    rl_initialize();
    
    // Loop to prompt the user for input
    while ((user_input = readline("\033[36;47;1mminishell\033[36;49;1m ➡️ \033[0m")) != NULL)
    {

        if (ft_strlen(user_input) > 0)
        {
            // Array of tokens inside of user_input structure 
            input_struct.input = user_input;
            input_struct.tokens = get_tokens(user_input);
            print_token(&input_struct);
        }

        // The readline function allocs memory, it might be freed
        free(user_input);

        // Start a new line of input
        rl_on_new_line();
    }

    return 0;
}
