/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:32:14 by ngastana          #+#    #+#             */
/*   Updated: 2024/03/26 13:10:50 by ngastana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef struct s_pipex
{
	int		fd[2];
	char	**env_str;
	int		infile;
	int		outfile;
	char	*path;
	char	**location_paths;
	char	**comands;
}				t_pipex;

/*CHILDREN*/
void	first_child(t_pipex pipex, char **argv, char **env);
void	second_child(t_pipex pipex, char **argv, char **env);

/*PIPEX*/
int		main(int argc, char **argv, char **envp);
void	ft_error(char *err, t_pipex pipex);

/*SPLIT*/
char	**ft_split(char *str);

/*UTILS*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*find_path(char **envp);
char	*ft_strjoin(char const	*s1, char const	*s2);

/*FREE_EXIT*/
void	free_exit(t_pipex pipex);
void	free_bigone(char **argv);

#endif