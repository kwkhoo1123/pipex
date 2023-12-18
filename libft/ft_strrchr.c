/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ strrchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:58:43 by kkah-wen          #+#    #+#             */
/*   Updated: 2022/10/04 15:58:44 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*last;

	last = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			last = (char *)&s[i];
		i++;
	}
	if (s[i] == (char) c)
		return ((char *)&s[i]);
	return (last);
}
