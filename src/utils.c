/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:30:34 by drubio-m          #+#    #+#             */
/*   Updated: 2023/06/29 14:25:05 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	open_file(char *argv, int selector)
{
	int	file;

	file = 0;
	if (selector == 1)
		file = open(argv, O_RDONLY);
	if (selector == 2)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file == -1)
		ft_error();
	return (file);
}

void	manage_child(char *argv[], char **envp, int *fd)
{
	int	infile;

	infile = open_file(argv[1], 1);
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	command(argv[2], envp);
}

void	parent_job(char *argv[], char **envp, int *fd)
{
	int	outfile;

	outfile = open_file(argv[4], 2);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	command(argv[3], envp);
}

void	ft_error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}
