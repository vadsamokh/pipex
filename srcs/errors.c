/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 12:24:40 by vbeech            #+#    #+#             */
/*   Updated: 2021/06/17 12:24:42 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	malloc_error_msg(void)
{
	ft_putstr_fd("Malloc error\n", 2);
	exit(0);
}

void	pipe_error_msg(void)
{
	ft_putstr_fd("Pipe error\n", 2);
	exit(0);
}

void	fork_error_msg(void)
{
	ft_putstr_fd("Fork error\n", 2);
	exit(0);
}

void	file_open_error_msg(void)
{
	ft_putstr_fd("Error: cannot find file or open it\n", 2);
	exit(0);
}

void	exec_error_msg(void)
{
	ft_putstr_fd("Error: cannot find executable or execute it\n", 2);
	exit(0);
}
