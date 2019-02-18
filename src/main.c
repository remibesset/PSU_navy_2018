/*
** EPITECH PROJECT, 2019
** Minishell1
** File description:
** main minishell1
*/

#include "minishell.h"

char *take_value_in_env(minishell_t *minishell, char *str_find)
{
    char *line_env = NULL;
    char *line_match = NULL;
    int i = 0;
    int k = 0;
    int passed = 0;

    for (i; minishell->env[i] != NULL; i++) {
        line_env = minishell->env[i];
        for (int j = 0; line_env[j] != '\0' && passed == 0; j++)
            passed = (compare_to_string(line_env, str_find) == 1) ? 1 : 0;
        if (passed == 1)
            break;
    }
    if (minishell->env[i] != NULL) {
        line_match = xmalloc(sizeof(char) * (my_strlen(minishell->env[i]) - 4));
        for (int j = my_strlen(str_find); minishell->env[i][j]; j++, k++)
            line_match[k] = minishell->env[i][j];
        line_match[k] = '\0';
    }
    return (line_match);
}

char **get_the_env(char **env)
{
    char **cmp_env;
    int i = 0;
    char *str;

    for (i; env[i] != NULL; i++);
    cmp_env = xmalloc(sizeof(char *) * (i + 1));
    for (i = 0; env[i] != NULL; i++) {
        str = my_strcpy(env[i]);
        cmp_env[i] = str;
    }
    cmp_env[i] = NULL;
    return (cmp_env);
}

void init_struct(minishell_t *minishell, char **envp)
{
    int nb_argument = 0;
    char *path;
    char *pwd = NULL;
    size_t size = 0;

    minishell->pass = 0;
    minishell->run = 1;
    minishell->env = get_the_env(envp);
    minishell->pwd = getcwd(pwd, size);
    path = take_value_in_env(minishell, "PATH=");
    minishell->path = (path != NULL) ? my_str_to_word_tab(path, ':',
&nb_argument) : NULL;
    minishell->nb_arg_path = nb_argument;
    free(path);
}

int main(int ac, char **av, char **env)
{
    minishell_t minishell;
    char *path;
    int nb_argument = 0;

    init_struct(&minishell, env);
    while (minishell.run == 1) {
        minishell_f(&minishell);
    }
    free_function_main(&minishell);
    return (0);
}