/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:22:26 by drubio-m          #+#    #+#             */
/*   Updated: 2023/11/15 12:46:13 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include <fcntl.h>

//Childs
void	manage_child(char *argv[], char **envp, int *fd);
void	parent_job(char *argv[], char **envp, int *fd);

//Utils
void	ft_error(int code);
int		open_file(char *argv, int selector);

//PATH & EXECVE
int		possible_path(char **envp);
char	*check_path(char *cmd, char **envp);
void	command(char *argv, char **envp);
#endif
