/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 10:19:32 by angassin          #+#    #+#             */
/*   Updated: 2023/05/01 18:45:44 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*
	Displays "error_msg" followed by a ’\n’ on the standard error
	and exit
*/
void	error_exit(char *error_msg)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	perror(error_msg);
	exit(EXIT_FAILURE);
}

int	infile_open(char *file)
{
	int	fd;

	fd = -1;
	fd = open(file, O_RDONLY, 0444);
	if (fd == -1)
		error_exit("can't open fd_in");
	return (fd);
}

int	outfile_open(char *file)
{
	int	fd;

	fd = -1;
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		error_exit("can't open fd_out");
	return (fd);
}

void	duplicate(int fd_src, int fd_dest, char *error)
{
	if (dup2(fd_src, fd_dest) == -1)
	{
		close(fd_src);
		error_exit(error);
	}
	close(fd_src);
}