/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:29:17 by juhong            #+#    #+#             */
/*   Updated: 2025/04/19 19:06:57 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*word_dup(const char *s, size_t start, size_t end)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i + start < end)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = 0;
	return (result);
}

static void	free_all(char **arr, size_t word_num)
{
	size_t	i;

	i = 0;
	while (i < word_num)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	temp(char const *s, char **result, char c, size_t i)
{
	size_t	word_num;
	size_t	start;

	word_num = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			result[word_num] = word_dup(s, start, i);
			if (!result[word_num])
			{
				free_all(result, word_num);
				return (0);
			}
			word_num++;
		}
	}
	result[word_num] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!result)
		return (NULL);
	if (temp(s, result, c, 0) == 0)
		return (NULL);
	return (result);
}
