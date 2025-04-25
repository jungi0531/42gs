/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:13:50 by juhong            #+#    #+#             */
/*   Updated: 2025/02/09 21:49:31 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);
void	ft_write_strs(int size, char **strs, char *sep, char **result);
void	ft_write_sep(char **result, char *sep, int *count);
int		ft_total_len(int size, char **strs, char *sep);

#ifdef TEST

int	main(void)
{
	char	*s1[] = {"hello", "world", "!!"};
	char	*s2 = "-";

	printf("%s\n", ft_strjoin(1, s1, s2));
	return (0);
}

#endif

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	char	*result;

	if (size == 0 || strs[0] == NULL)
	{
		result = (char *)malloc(sizeof(char));
		if (!result)
			return (NULL);
		result[0] = 0;
		return (result);
	}
	len = ft_total_len(size, strs, sep);
	result = (char *)malloc(sizeof(char) * len);
	if (!result)
		return (NULL);
	ft_write_strs(size, strs, sep, &result);
	return (result);
}

void	ft_write_strs(int size, char **strs, char *sep, char **result)
{
	int		i;
	int		ii;
	int		count;

	count = 0;
	i = 0;
	while (i < size)
	{
		ii = 0;
		while (strs[i][ii])
			(*result)[count++] = strs[i][ii++];
		if (i < size - 1)
			ft_write_sep(result, sep, &count);
		else
			result[count++] = 0;
		i++;
	}
}

void	ft_write_sep(char **result, char *sep, int *count)
{
	int	i;

	i = 0;
	while (sep[i])
		(*result)[(*count)++] = sep[i++];
}

int	ft_total_len(int size, char **strs, char *sep)
{
	int	i;
	int	ii;
	int	strs_len;
	int	sep_len;

	strs_len = 0;
	sep_len = 0;
	i = 0;
	while (i < size)
	{
		ii = 0;
		while (strs[i][ii])
		{
			strs_len++;
			ii++;
		}
		i++;
	}
	while (sep[sep_len])
		sep_len++;
	return (strs_len + sep_len * (size - 1) + 1);
}
