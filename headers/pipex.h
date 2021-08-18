/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:37:20 by vbeech            #+#    #+#             */
/*   Updated: 2021/06/10 14:37:21 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>

typedef struct s_args
{
	char	**cmd0;
	char	*path0;
	char	**cmd1;
	char	*path1;
}	t_args;

void	cmd_init(t_args *args, char **argv, char **envp);
void	child(int *p, char **argv, char **envp, t_args *args);
void	parent(int *p, char **argv, char **envp, t_args *args);
void	spl_clear(char **spl);
char	*path_work(char *cmd, char **envp);
char	*find_path1(char *cmd, char *paths);
char	*find_path2(char **spl_paths, char *cmd, int i);
void	clear_all(t_args *args);
void	invalid_args_error_msg(void);
void	malloc_error_msg(void);
void	pipe_error_msg(void);
void	fork_error_msg(void);
void	file_open_error_msg(void);
void	exec_error_msg(void);

#endif
