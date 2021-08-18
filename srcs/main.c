/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 12:37:11 by vbeech            #+#    #+#             */
/*   Updated: 2021/06/17 12:37:13 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	invalid_args_error_msg(void)
{
	ft_putstr_fd("Invalid number of arguments\n", 2);
	exit(0);
}

void	spl_clear(char **spl)
{
	int	i;

	i = 0;
	while (spl[i] != NULL)
	{
		free(spl[i]);
		i++;
	}
	free(spl);
}

void	parent(int *p, char **argv, char **envp, t_args *args)
{
	int		outfile;

	wait(0);
	close(p[1]);
	dup2(p[0], 0);
	outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (outfile < 0)
	{
		clear_all(args);
		file_open_error_msg();
	}
	dup2(outfile, 1);
	if (execve(args->path1, args->cmd1, envp) == -1)
	{
		clear_all(args);
		exec_error_msg();
	}
}

void	child(int *p, char **argv, char **envp, t_args *args)
{
	int		infile;

	close(p[0]);
	dup2(p[1], 1);
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		clear_all(args);
		file_open_error_msg();
	}
	dup2(infile, 0);
	if (execve(args->path0, args->cmd0, envp) == -1)
	{
		clear_all(args);
		exec_error_msg();
	}
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		p[2];
	t_args	args;

	if (argc < 5)
		invalid_args_error_msg();
	if (pipe(p) == -1)
		pipe_error_msg();
	cmd_init(&args, argv, envp);
	pid = fork();
	if (pid == -1)
		fork_error_msg();
	else if (pid == 0)
		child(p, argv, envp, &args);
	else
		parent(p, argv, envp, &args);
}
