/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:54:02 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/05 10:40:30 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_list(char **list)
{
	int		i;

	i = -1;
	while (list[++i])
		free(list[i]);
	free(list);
}

void	error(void)
{
	perror("Error Occured");
	exit(1);
}

char	*get_path(char *cmd, char **envp)
{
	char	**path_list;
	char	*path_sub;
	char	*path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	path_list = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path_list[i])
	{
		path_sub = ft_strjoin(path_list[i], "/");
		path = ft_strjoin(path_sub, cmd);
		free(path_sub);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	free_list(path_list);
	return (0);
}

void	execute(char *av, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	path = get_path(cmd[0], envp);
	if (!path)
	{
		free(path);
		free_list(cmd);
		error();
	}
	if (execve(path, cmd, envp) == -1)
		error();
}
