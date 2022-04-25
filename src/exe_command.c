#include "../minishell.h"

char	*find_command(char **arg)
{
    int	i;

    i = 0;
    while (arg[i])
    {
        if (ft_strlen(arg[i]) != 0)
            return (ft_strdup(arg[i]));
        i++;
    }
    return (NULL);
}

int	get_variable_env(t_info *inf, char **adr, char *key_word, int n)
{
    t_env	*temp;

    temp = inf->env_lst;
    while (temp != NULL)
    {
        if (ft_strncmp(temp->str, key_word, n) == 0)
        {
            *adr = temp->str + n;
            return (0);
        }
        temp = temp->next;
    }
    return (1);
}

char	*search_in_arr(char **arr, char *command)
{
    char	*full_path;
    char	*path;
    int		i;

    i = 0;
    while (arr[i])
    {
        path = ft_strjoin(arr[i], "/");
        full_path = ft_strjoin(path, command);
        free(path);
        if (access(full_path, X_OK) == 0)
        {
            free(command);
            return (full_path);
        }
        free(full_path);
        i++;
    }
    full_path = ft_strdup(command);
    free(command);
    return (full_path);
}

char	*find_command_in_env(char *cmd, t_info *inf)
{
    char	*env;
    char	*full_path;
    char	**arr;

    if (get_variable_env(inf, &env, "PATH=", 5))
        return (NULL);
    arr = ft_split(env, ':');
    if (!arr)
        return (NULL);
    full_path = search_in_arr(arr, cmd);
    free_arr(arr);
    return (full_path);
}

char    **init_res(char **res, char **arg, t_info *inf)
{
    int i;
    int size;
    while (arg[i])
    {
        if (ft_strlen(arg[i]) != 0)
            res[size++] = ft_strdup(arg[i]);
        i++;
    }
    res[size] = NULL;
    if (!ft_strchr(res[0] , '/'))
        res[0] = find_command_in_env(res[0], inf);
    return (res);
}

char    **re_bild_argv(char **arg, t_info *inf)
{
    int i;
    int size;
    char **res;

    i = 0;
    size = 0;
    while (arg[i])
    {
        if (ft_strlen(arg[i]) != 0)
            size++;
        i++;
    }
    res = malloc(sizeof(char *) * size + 1);
    if (!res)
        return (NULL);
    res = init_res(res, arg, inf);
    return (res);
}

char    **bild_env(t_env *env_list)
{
    char    **env;
    t_env   *tmp;
    int     size;

    size = 0;
    tmp = env_list;
    while (tmp->next)
    {
        size++;
        tmp = tmp->next;
    }
    env = (char **) malloc(sizeof(char *) * size);
    if (!env)
        exit(1);
    size = 0;
    tmp = env_list;
    while (tmp->next)
    {
        env[size++] = tmp->str;
        tmp = tmp->next;
    }
//    size = 0;
//    while (env[size])
//        printf("%s\n", env[size++]);
    return (env);
}

void    child(char *cmd, t_info *inf, int ft_in, int fd_out)
{
    char **argv;

    argv = re_bild_argv(inf->pipels->arg, inf);
//    if (inf->pipels->is_heredoc)
//    if (inf->is_pipe);
//    printf("argv[0]:%s\n", argv[0]);

//    bild_env(inf->env_lst);
    execve(argv[0], argv, bild_env(inf->env_lst));
//    execute(argv[0], argv, inf->env);
    free_arr(argv);
    exit(127);
}

void    parent(pid_t pid, t_info *inf, int pipe_in, int pipe_out)
{
    int return_exit;

    if (inf->is_pipe)
    {
        close(pipe_out);
        dup2(pipe_in, inf->tmp_in);
    }
    waitpid(pid, &return_exit, 0);
    gl_exit = WEXITSTATUS(return_exit);
    close(inf->pipels->fd_in);
    close(inf->pipels->fd_out);
    close(inf->pipels->fr_re_out);
    close(pipe_in);
    close(pipe_out);
}

void    exe_fork(char *cmd, t_info *inf)
{
    pid_t   pid;

    pid = fork();
    if (pid < 0)
    {
        perror(ERROR_NAME);
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
        child(cmd, inf, inf->pipels->fd_in, inf->pipels->fd_out);
    else
        parent(pid, inf, inf->pipels->fd_in, inf->pipels->fd_out);
}

int cheak_pipe_redirects(t_pipels *pipels)
{
    int i;
    int count;

    count = 0;
    if (pipels->is_redirect != -1)
    {
        i = 0;
        while (pipels->arg[i])
        {
            if (ft_strlen(pipels->arg[i]) == 0)
                count++;
            i++;
        }
    }
    if (pipels->is_redirect + pipels->is_dollar != count)
        return (1);
    return (0);
}

void    exe_void(t_info *inf)
{
    char *cmd;
    char *arg[3];

    close(inf->pipels->fd_in);
    close(inf->pipels->fd_out);
    close(inf->pipels->fr_re_out);
    close(inf->pipe_fd_in);
    close(inf->pipe_fd_out);
    cmd = find_command(inf->pipels->arg);
    if (!cmd)
        cmd = ft_strdup("");
    else
        if (!ft_strchr(cmd, '/'))
            cmd = find_command_in_env(cmd, inf);
    arg[0] = cmd;
    arg[1] = "";
    arg[2] = NULL;
    execute_fork_old(cmd, arg, inf);
}

//все оставшиеся команды
void    exe_command(t_info *inf)
{
    char    *cmd;

    if (cheak_pipe_redirects(inf->pipels))
    {
        printf("RR\n");
        exe_void(inf);
    }
    else {
        printf("RE\n");
        cmd = find_command(inf->pipels->arg);
        if (!cmd) {
            close(inf->pipels->fd_in);
            close(inf->pipels->fd_out);
            close(inf->pipels->fr_re_out);
            return;
        }
        exe_fork(cmd, inf);
        free(cmd);
    }
}

