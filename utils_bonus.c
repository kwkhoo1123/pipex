/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:27:23 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/05 12:30:50 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *av, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(av, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (i == 1)
		file = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (i == 2)
		file = open(av, O_RDONLY);
	if (file == -1)
		error();
	return (file);
}

int	get_next_line(char **line)
{
	char	*buffer;
	char	c;
	int		i;
	int		rd;

	i = 0;
	rd = 0;
	buffer = malloc((8192) * sizeof(char));
	if (!buffer)
		return (-1);
	rd = read(0, &c, 1);
	while (rd && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		rd = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (rd);
}

void	bonus_err(void)
{
	ft_putstr_fd("Error: incorrect format arguments\n", 2);
	ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 2);
	ft_putstr_fd("./pipex \"here_doc\" <LIMITER> <cmd> <cmd1> <...> <file>\n", 2);
	exit(1);
}
