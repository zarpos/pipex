/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:12:23 by drubio-m          #+#    #+#             */
/*   Updated: 2023/08/28 20:13:42 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// this function checks if the PATH exists
// 0 on success, 1 on failure
int	possible_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (0);
		i++;
	}
	ft_error(1);
	return (0);
}

// this function checks if the command exists in the PATH
// it also checks if the command is a path itself
// it checks if the file exists
char	*check_path(char *cmd, char **envp)
{
	int		i;
	char	**all_paths;
	char	*single_path;
	char	*part_path;

	i = 0;
	if (access(cmd, F_OK) == 0)
		return (cmd);
	if (possible_path(envp) == 1)
		return (NULL);
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	all_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (all_paths[i])
	{
		part_path = ft_strjoin(all_paths[i], "/");
		single_path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(single_path, F_OK) == 0)
			return (single_path);
		i++;
	}
	return (NULL);
}

void	command(char *argv, char **envp)
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (execve(check_path(cmd[0], envp), cmd, envp) == -1)
		ft_error(127);
}
