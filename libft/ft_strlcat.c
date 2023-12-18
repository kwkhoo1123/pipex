/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:51:45 by kkah-wen          #+#    #+#             */
/*   Updated: 2022/10/17 18:58:34 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	des_size;
	size_t	src_size;

	des_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (len <= des_size)
		return (len + src_size);
	i = 0;
	while ((des_size + i) < len - 1 && src[i])
	{	
		dst[des_size + i] = src[i];
		i++;
	}
	dst[des_size + i] = '\0';
	return (src_size + des_size);
}
/* 
int main() {
	unsigned int nb = 13;
	char str1[99] = "abcde"; //5 char
	char str1_clone[99] = "abcde"; //dupe for ft test
	char str2[40] = "123456789X"; //10 char
	int i;

	i = strlcat(str1, str2, nb);
	printf("dest string: %s \n", str1);
	printf("returned value: %d \n", i);
	i = ft_strlcat(str1_clone, str2, nb);
	printf("ft ver dest: %s \n", str1_clone);
	printf("returned value: %d \n", i);
	return (0);
} */