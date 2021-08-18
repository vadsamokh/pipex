/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:36:24 by vbeech            #+#    #+#             */
/*   Updated: 2021/06/17 11:36:28 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_init(t_args *args, char **argv, char **envp)
{
	args->cmd0 = ft_split(argv[2], ' ');
	if (args->cmd0 == NULL)
		malloc_error_msg();
	args->cmd1 = ft_split(argv[3], ' ');
	if (args->cmd1 == NULL)
	{
		spl_clear(args->cmd0);
		malloc_error_msg();
	}
	args->path0 = path_work((args->cmd0)[0], envp);
	if (args->path0 == NULL)
	{
		spl_clear(args->cmd0);
		spl_clear(args->cmd1);
		malloc_error_msg();
	}
	args->path1 = path_work((args->cmd1)[0], envp);
	if (args->path1 == NULL)
	{
		spl_clear(args->cmd0);
		spl_clear(args->cmd1);
		free(args->path0);
		malloc_error_msg();
	}
}

char	*path_work(char *cmd, char **envp)
{
	int		i;
	char	**var;
	char	*path;

	if (ft_strchr(cmd, '/') != NULL)
		return (cmd);
	i = 0;
	while (envp[i] != NULL)
	{
		var = ft_split(envp[i], '=');
		if (var == NULL)
			return (NULL);
		if (ft_strcmp(var[0], "PATH") == 0)
		{
			path = find_path1(cmd, var[1]);
			spl_clear(var);
			return (path);
		}
		spl_clear(var);
		i++;
	}
	return (cmd);
}

char	*find_path1(char *cmd, char *paths)
{
	char	**spl_paths;
	char	*path;
	int		i;

	i = 0;
	spl_paths = ft_split(paths, ':');
	if (spl_paths == NULL)
		return (NULL);
	while (spl_paths[i] != NULL)
	{
		path = find_path2(spl_paths, cmd, i);
		if (path == NULL)
			return (NULL);
		if (access(path, 1) == 0)
		{
			spl_clear(spl_paths);
			return (path);
		}
		free(path);
		i++;
	}
	spl_clear(spl_paths);
	return (cmd);
}

char	*find_path2(char **spl_paths, char *cmd, int i)
{
	char	*tmp;
	char	*path;

	tmp = ft_strjoin(spl_paths[i], "/");
	if (tmp == NULL)
	{
		spl_clear(spl_paths);
		return (NULL);
	}
	path = ft_strjoin(tmp, cmd);
	free(tmp);
	if (path == NULL)
	{
		spl_clear(spl_paths);
		return (NULL);
	}
	return (path);
}

void	clear_all(t_args *args)
{
	if (args->path0 != (args->cmd0)[0])
		free(args->path0);
	if (args->path1 != (args->cmd1)[0])
		free(args->path1);
	spl_clear(args->cmd0);
	spl_clear(args->cmd1);
}
