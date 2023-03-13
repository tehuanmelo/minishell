/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehuanmelo <tehuanmelo@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:26:41 by tehuanmelo        #+#    #+#             */
/*   Updated: 2023/03/08 23:21:50 by tehuanmelo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// Generic function just to print the output of split function 
void print_token(char **token)
{
    while (*token)
    {
        ft_putstr(*token);
        ft_putstr("\n");
        token++;
    }
}

// This for your main testing.
// int main() {
//     char *input;
//     char **token;
//     t_args *args;
    
//     // Initialize Readline
//     rl_initialize();

//     // Loop to prompt the user for input
//     while ((input = readline("\033[36;47;1mminishell\033[36;49;1m ➡️ \033[0m")) != NULL) 
//     {

//         // Split the input using spaces
//         token = ft_split(input, ' ');
        
//         // Generic function just to print and test the output of split
//         print_token(token);
        

//         // The readline function allocs memory, it might be freed
//         free(input);

//         // Start a new line of input
//         rl_on_new_line();
//     }

//     return 0;
// }


//These as of now for testing whether the commands work or not. 
int main() {
    char *input;
    char **token;
   t_data *data;
   data = NULL;

    // Initialize Readline
    rl_initialize();

    // Loop to prompt the user for input
    while (1) 
    {
        printf("\033[36;47;1mminishell\033[36;49;1m ➡️ \033[0m");

        input = readline("");
        // Split the input using spaces
        token = ft_split(input, ' ');
        
        // Printing out the built_ins
        if(strcmp(token[0], "pwd") == 0)
            ft_pwd_built_in(data, token);
        else if(strcmp(token[0], "echo") == 0)
            ft_echo_built_in(data, token);
        // else if (token[0] != NULL && strcmp(token[0], "env") == 0) 
        //     ft_env_built_in(data, token);
        else
            print_token(token);  

        // The readline function allocs memory, it might be freed
        free(input);
        free (token);

        // Start a new line of input
        rl_on_new_line();
    }

    return 0;
}