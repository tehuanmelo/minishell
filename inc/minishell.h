#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../src/libft/inc/libft.h"

#define SPACE 32
#define DOUB_QUOT 34
#define SING_QUOT 39

#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_BLUE "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN "\033[36m"
#define COLOR_RESET "\033[0m"

typedef struct s_command
{
    char *command;
    char *option;
    char **redirect;
    char **files;
}   t_command;

typedef struct s_input
{
    char *input;
    char **tokens;
    int number_of_commands;
    t_command *commands_array;
}   t_input;

char **get_tokens(char *str);

#endif