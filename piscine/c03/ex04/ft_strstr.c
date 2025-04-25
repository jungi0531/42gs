/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:29:38 by juhong            #+#    #+#             */
/*   Updated: 2025/01/30 14:15:08 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find);
int		ft_strcmp(char *s1, char *s2, int index);

char	*ft_strstr(char *str, char *to_find)
{
	int	index;

	if (!(to_find[0]))
		return (NULL);
	index = 0;
	while (str[index])
	{
		if (ft_strcmp(str, to_find, index) == 0)
			return (&str[index]);
		index++;
	}
	return (NULL);
}

int	ft_strcmp(char *s1, char *s2, int index)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		if (s1[index] != s2[i])
			return (s1[index] - s2[i]);
		index++;
		i++;
	}
	return (0);
}

#ifdef TEST

int	main(void)
{
	char	*s1 = "";
	char	*s2 = "";

	printf("%s\n", strstr(s1, s2));
	printf("%s\n", ft_strstr(s1, s2));
	return (0);
}

#endif
