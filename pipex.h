/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:54:10 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/04 15:35:25 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"

void	error(void);
char	*get_path(char *cmd, char **envp);
void	execute(char *argv, char **envp);
void	free_list(char **list);

int		open_file(char *av, int i);
int		get_next_line(char **line);
void	bonus_err(void);

#endif