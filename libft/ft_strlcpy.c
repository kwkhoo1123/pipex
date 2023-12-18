/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:08:32 by kkah-wen          #+#    #+#             */
/*   Updated: 2022/11/07 15:31:57 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t d_size)
{
	size_t	i;

	if (d_size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < d_size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/* 
int main() {
	unsigned int nb = 3;
	char str1[99] = "abcdefg"; //7 char
	char str1_clone[99] = "abcdefg"; //dupe for ft test
	char str2[40] = "1234567890"; //10 char
	int i;

	i = strlcpy(str1, str2, nb);
	printf("dest string: %s \n", str1);
	printf("returned value: %d \n", i);
	i = ft_strlcpy(str1_clone, str2, nb);
	printf("ft ver dest: %s \n", str1_clone);
	printf("returned value: %d \n", i);
	return (0);
} */