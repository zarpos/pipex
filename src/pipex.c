/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:57:03 by drubio-m          #+#    #+#             */
/*   Updated: 2023/10/21 19:24:17 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// the main function is the parent process.
// it creates a pipe and a child process
// then it waits for the child process to finish and executes the second command
// with the output of the first command
int	main(int argc, char *argv[], char **envp)
{
	int		fd[2];
	pid_t	child_pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error(1);
		child_pid = fork();
		if (child_pid == -1)
			ft_error(1);
		if (child_pid == 0)
			manage_child(argv, envp, fd);
		waitpid(child_pid, NULL, 0);
		parent_job(argv, envp, fd);
	}
	else
		ft_error(1);
	return (0);
}

// TODO: (Test 8)Hacer que funcione con esto: ./pipex /dev/urandom "cat" "head" out
	//! Se tiene que ejecutar y ES OPCIONAL la creación del out.
