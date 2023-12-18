/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:01:47 by kkah-wen          #+#    #+#             */
/*   Updated: 2022/10/19 15:57:09 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**error_clear(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

int	count_splits(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		begin;
	int		index;

	arr = (char **)malloc(sizeof(char *) * (count_splits(s, c) + 1));
	if (!s || !arr)
		return (NULL);
	i = 0;
	index = -1;
	while (++index < count_splits(s, c))
	{
		while (s[i] == c)
			i++;
		begin = i;
		while (s[i] != c && s[i])
			i++;
		arr[index] = ft_substr(s, begin, i - begin);
		if (!arr[index])
			return (error_clear(arr));
	}
	arr[index] = NULL;
	return (arr);
}
/* 
int	main(int ac, char **av)
{
	char	**str;
	int		i = 0;
	if (ac == 3)
	{
		str = ft_split(av[1], av[2][0]);
		while(str[i])
		{
			printf("str %s\n", str[i]);
			i++;
		}
	}
	return (0);
} */