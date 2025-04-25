/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:03:30 by juhong            #+#    #+#             */
/*   Updated: 2025/02/09 18:28:51 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	**ft_split(char *str, char *charset);
int		count_words(char *str, char *charset);
int		is_charset(char *str, char *charset, int i);
int		ft_strlen(char *str);
char	*ft_strdup(char *str, int prv_i, int i);

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		prv_i;
	int		count;
	char	**temp;

	temp = (char **)malloc(sizeof(char *) * (count_words(str, charset) + 1));
	i = 0;
	prv_i = 0;
	count = 0;
	while (str[i])
	{
		if (is_charset(str, charset, i))
			i += ft_strlen(charset);
		else
		{
			prv_i = i;
			while (!is_charset(str, charset, i) && str[i])
				i++;
			temp[count++] = ft_strdup(str, prv_i, i - 1);
		}
	}
	temp[count] = NULL;
	return (temp);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;
	int	word;

	i = 0;
	count = 0;
	word = 0;
	while (str[i])
	{
		if (is_charset(str, charset, i))
		{
			i += ft_strlen(charset);
			word = 0;
		}
		else if (word == 0)
		{
			count++;
			word = 1;
			i++;
		}
		else
			i++;
	}
	return (count);
}

int	is_charset(char *str, char *charset, int i)
{
	int	index;

	index = 0;
	while (index < ft_strlen(charset) && str[i + index])
	{
		if (str[i + index] != charset[index])
			return (0);
		index++;
	}
	if (index != ft_strlen(charset))
		return (0);
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str, int prv_i, int i)
{
	int		index;
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (i - prv_i + 2));
	if (!temp)
		return (NULL);
	index = prv_i;
	while (index <= i)
	{
		temp[index - prv_i] = str[index];
		index++;
	}
	temp[index - prv_i] = 0;
	return (temp);
}
