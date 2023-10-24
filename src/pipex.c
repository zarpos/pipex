/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:57:03 by drubio-m          #+#    #+#             */
/*   Updated: 2023/10/24 14:52:11 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// This function manages the child process
// If child_pid == 0, it means that it is the child process 
// else it is the parent process
// The child process will execute the first command
// The parent process will execute the second command
// We close the fd[0] and fd[1] because we don't need them anymore
// The parent process will wait for the child process to finish
// The child process will wait for the parent process to finish
int	main(int argc, char *argv[], char **envp)
{
	int		fd[2];
	pid_t	child_pid;
	pid_t	father_pid;

	if (argc != 5 || pipe(fd) == -1)
		ft_error(1);
	child_pid = fork();
	if (child_pid == -1)
		ft_error(1);
	if (child_pid == 0)
		manage_child(argv, envp, fd);
	else
	{
		father_pid = fork();
		if (father_pid == -1)
			ft_error(1);
		if (father_pid == 0)
			parent_job(argv, envp, fd);
		close(fd[0]);
		close(fd[1]);
		waitpid(child_pid, NULL, 0);
		waitpid(father_pid, NULL, 0);
	}
	return (0);
}
