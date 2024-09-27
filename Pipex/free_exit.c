/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:53:57 by ngastana          #+#    #+#             */
/*   Updated: 2024/03/26 13:06:14 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_bigone(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free (argv);
}

void	free_exit(t_pipex pipex)
{
	int	i;

	i = 0;
	if (pipex.env_str != NULL)
		free_bigone(pipex.env_str);
	if (pipex.location_paths != NULL)
		free_bigone(pipex.location_paths);
	if (pipex.comands != NULL)
		free_bigone(pipex.comands);
	exit(1);
}
