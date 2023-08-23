/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:30:34 by drubio-m          #+#    #+#             */
/*   Updated: 2023/08/23 19:29:55 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// open_file() opens a file and returns the file descriptor
// if the file doesn't exist, it calls ft_error() with the code 1
int	open_file(char *argv, int selector)
{
	int	file;

	file = 0;
	if (selector == 1)
		file = open(argv, O_RDONLY);
	if (selector == 2)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file == -1)
		ft_error(1);
	return (file);
}

// manage_child() is the child process, it opens the input file and
// redirects the output to the pipe
void	manage_child(char *argv[], char **envp, int *fd)
{
	int	infile;

	infile = open_file(argv[1], 1);
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	command(argv[2], envp);
}

// parent_job() is the parent process, it opens the output file and
// redirects the input to the pipe
void	parent_job(char *argv[], char **envp, int *fd)
{
	int	outfile;

	outfile = open_file(argv[4], 2);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	command(argv[3], envp);
}

void	ft_error(int code)
{
	perror("\033[31mError");
	exit(code);
}
