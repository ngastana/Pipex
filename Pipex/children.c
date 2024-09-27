/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:56:46 by ngastana          #+#    #+#             */
/*   Updated: 2024/03/27 11:16:09 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(t_pipex pipex, char **argv, char **env)
{
	int		i;
	char	*location;
	char	*tmp;

	dup2(pipex.infile, STDIN_FILENO);
	dup2(pipex.fd[1], STDOUT_FILENO);
	close(pipex.fd[0]);
	close(pipex.infile);
	close(pipex.fd[1]);
	i = 0;
	pipex.comands = ft_split(argv[2]);
	while (pipex.location_paths[i] != NULL)
	{
		tmp = ft_strjoin(pipex.location_paths[i], "/");
		location = ft_strjoin(tmp, pipex.comands[0]);
		if (access(location, X_OK) == 0)
		{
			if (execve(location, pipex.comands, env) == -1)
				ft_error("Execve", pipex);
		}
		i++;
		free (location);
		free (tmp);
	}
	free_bigone(pipex.comands);
}

void	second_child(t_pipex pipex, char **argv, char **env)
{
	int		i;
	char	*location;
	char	*tmp;

	dup2(pipex.fd[0], STDIN_FILENO);
	dup2(pipex.outfile, STDOUT_FILENO);
	close(pipex.fd[0]);
	close(pipex.fd[1]);
	i = 0;
	pipex.comands = ft_split(argv[3]);
	while (pipex.location_paths[i] != NULL)
	{
		tmp = ft_strjoin(pipex.location_paths[i], "/");
		location = ft_strjoin(tmp, pipex.comands[0]);
		if (access(location, X_OK) == 0)
		{
			if (execve(location, pipex.comands, env) == -1)
				ft_error("Execve", pipex);
		}
		i++;
		free (location);
		free (tmp);
	}
	close(pipex.outfile);
}
