/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:31:34 by ngastana          #+#    #+#             */
/*   Updated: 2024/03/27 11:22:13 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_close_all(t_pipex pipex)
{
	close(pipex.outfile);
	close(pipex.infile);
	close(pipex.fd[0]);
	close(pipex.fd[1]);
	free_exit(pipex);
}

static int	setup_pipes_and_forks(t_pipex pipex, char **argv, char **env)
{
	pid_t	pid;
	int		i;

	if (pipe(pipex.fd) < 0)
		ft_error("Pipe", pipex);
	pipex.path = find_path(env);
	pipex.location_paths = ft_split(pipex.path);
	i = 0;
	pid = fork();
	if (pid == -1)
		ft_error("Error al crear primer hijo", pipex);
	if (pid == 0)
		first_child(pipex, argv, env);
	pid = fork();
	if (pid == -1)
		ft_error("Error al crear segundo hijo", pipex);
	if (pid == 0)
		second_child(pipex, argv, env);
	free_bigone(pipex.location_paths);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (argc != 5)
		return (write(2, "Invalid number of arguments\n", 28), 1);
	bzero(&pipex, sizeof(struct s_pipex));
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0777);
	if (pipex.outfile < 0)
		ft_error("Outfile", pipex);
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		ft_error("Infile", pipex);
	if (setup_pipes_and_forks(pipex, argv, env) != 0)
		return (1);
	wait(NULL);
	ft_close_all(pipex);
	return (0);
}

void	ft_error(char *err, t_pipex pipex)
{
	perror(err);
	ft_close_all(pipex);
	free_exit(pipex);
	exit (1);
}
