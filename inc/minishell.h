#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
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


// # ===================================================================== #
// # =============================== PARSING ============================= #
// # ===================================================================== #

typedef struct s_command
{
    char *command;
    char *option;
    char **redirect;
    char **files;
}   t_command;

char **get_tokens(char *str);


// # ===================================================================== #
// # ============================= EXECUTION ============================= #
// # ===================================================================== #

// As of right now, this will be a temporary parsing utils that I will use to run the code. 
typedef struct s_data
{
	char		*user_input;
    char        **tokens;
	char		**env;
	pid_t		pid;
}	t_data;


// ================================ BUILT_INS =========================== #
int	ft_echo_built_in(t_data *data, char **args);
int ft_pwd_built_in(t_data *data, char **args);
// int	ft_env_built_in(t_data *data, char **args);


#endif