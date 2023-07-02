/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:57:03 by drubio-m          #+#    #+#             */
/*   Updated: 2023/07/02 20:02:00 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
