/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:00:07 by juhong            #+#    #+#             */
/*   Updated: 2025/02/04 20:13:55 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char	*ft_strdup(char *src);
int		ft_strlen(char *str);

#ifdef TEST

int	main(void)
{
	return (0);
}

#endif

char	*ft_strdup(char *src)
{
	int		i;
	char	*temp;

	temp = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!temp)
	{
		errno = ENOMEM;
		return (NULL);
	}
	i = 0;
	while (src[i])
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = 0;
	return (temp);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
