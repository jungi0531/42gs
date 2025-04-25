/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:52:33 by juhong            #+#    #+#             */
/*   Updated: 2025/02/13 14:58:30 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;
	unsigned int	ii;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = dest_len;
	ii = 0;
	while (src[ii] && (ii + dest_len + 1) < size)
	{
		dest[i++] = src[ii++];
		i++;
		ii++;
	}
	dest[i] = 0;
	if (dest_len < size)
		return (src_len + dest_len);
	return (size + src_len);
}

#ifdef TEST

int	main(void)
{
	char	s1[100] = "hel
	char	*s2 = "happy";

	printf("%u\n", ft_strlcat(s1, s2, 15));
	return (0);
}

#endif
