/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:00:03 by juhong            #+#    #+#             */
/*   Updated: 2025/02/12 18:47:54 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	**ft_split(char *str, char *charset);
void	ft_word_sep(char *str, char *charset, char **temp);
int		count_words(char *str, char *charset);
int		is_charset(char c, char *charset);
char	*ft_strdup(char *str, int prv_i, int i);

char	**ft_split(char *str, char *charset)
{
	char	**temp;

	temp = (char **)malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (!str || count_words(str, charset) == 0)
	{
		temp[0] = 0;
		return (temp);
	}
	ft_word_sep(str, charset, temp);
	return (temp);
}

void	ft_word_sep(char *str, char *charset, char **temp)
{
	int	i;
	int	prv_i;
	int	count;

	i = 0;
	prv_i = 0;
	count = 0;
	while (str[i])
	{
		if (is_charset(str[i], charset))
			i++;
		else
		{
			prv_i = i;
			while (is_charset(str[i], charset) == 0 && str[i])
				i++;
			temp[count++] = ft_strdup(str, prv_i, i);
		}
	}
	temp[count] = NULL;
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;
	int	word;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	word = 0;
	while (str[i])
	{
		if (is_charset(str[i], charset))
			word = 0;
		else if (word == 0)
		{
			count++;
			word = 1;
		}
		i++;
	}
	return (count);
}

int	is_charset(char c, char *charset)
{
	int	i;

	if (!charset)
		return (0);
	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *str, int prv_i, int i)
{
	int		index;
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (i - prv_i + 1));
	if (!temp)
		return (NULL);
	index = prv_i;
	while (index < i)
	{
		temp[index - prv_i] = str[index];
		index++;
	}
	temp[index - prv_i] = 0;
	return (temp);
}
