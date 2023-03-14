/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:24:41 by mbin-nas          #+#    #+#             */
/*   Updated: 2023/03/14 15:09:51 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*get_command(char **path, char *cmd)
{
	char	*temp;
	char	*get_command;

	while (*path)
	{
        // printf("%s\n", *path);
		temp = ft_strjoin(*path, "/");
        printf("Temp %s\n", temp);
		get_command = ft_strjoin(temp, cmd);
        printf("CMD: %s\n", cmd);
        printf("%s\n", get_command);
		free(temp);
		if (access(get_command, 0) == 0)
		{
			return (get_command);
		}
		free(get_command);
		path++;
	}
    // printf("%s\n", get_command);
	return (NULL);
}

char	*find_path(char **envp)
{
	if (envp)
	{
		while (*envp)
		{
			if (ft_strncmp("PATH=", *envp, 5) == 0)
				return (*envp + 5);
			envp++;
		}
	}
	return (0);
}

int ft_env_built_in(t_data *data, char **args)
{
    
     if (args[0] == NULL) {
        char **envp = data->env;
        data->user_input = "env";
        while (*envp != NULL) {
            printf("%s\n", *envp);
            envp++;
        }
        return 0;
    }
    data->user_input = "env";
    // Otherwise, try to execute the command with the modified environment
    if (execve(get_command(ft_split(find_path(data->env), ':'), data->user_input), args, data->env) == -1) {
        printf("%s\n", ft_split(find_path(data->env), ':')[1]);
        perror("execvp");
        return 1;
    }

    return 0;
}