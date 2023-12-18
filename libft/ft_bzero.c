/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:03:44 by kkah-wen          #+#    #+#             */
/*   Updated: 2022/10/03 19:13:08 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t len)
{
	char	*pt;
	size_t	i;

	pt = (char *)str;
	i = 0;
	while (i < len)
	{	
		pt[i] = '\0';
		i++;
	}
}
/* 
int	main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_bzero(av[1], atoi(av[2]));
		printf("%s\n", av[1]);
	}
	return (0);
}
 */