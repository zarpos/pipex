/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:30:34 by drubio-m          #+#    #+#             */
/*   Updated: 2023/06/19 20:36:01 by drubio-m         ###   ########.fr       */
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
	
}

void	parent_job(char *argv[], char **envp, int *fd)
{
	int	outfile;

	outfile = open_file(argv[4], 2);

}

void	ft_error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}
