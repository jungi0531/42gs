/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:13:38 by juhong            #+#    #+#             */
/*   Updated: 2025/01/29 21:47:13 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	ii;	

	i = 0;
	ii = 0;
	while (dest[i])
		i++;
	while (src[ii])
		dest[i++] = src[ii++];
	dest[i] = 0;
	return (dest);
}

#ifdef TEST

int	main(void)
{
	return (0);
}

#endif
