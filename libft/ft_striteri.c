/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:19:04 by kkah-wen          #+#    #+#             */
/*   Updated: 2022/10/07 17:20:39 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/* 
void	test_func(unsigned int i, char *c)
{
	printf("test: index = %d, *c = %s\n", i, c);
}

int main(void)
{
	char str[10] = "abcde";
	printf("The str was %s\n", str);
	ft_striteri(str, test_func);
	printf("The result is now %s\n", str);
	return (0);
} */