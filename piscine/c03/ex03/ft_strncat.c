/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:13:38 by juhong            #+#    #+#             */
/*   Updated: 2025/01/29 21:50:44 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	ii;

	i = 0;
	ii = 0;
	while (dest[i])
		i++;
	while (ii < nb && src[ii])
	{
		dest[i++] = src[ii++];
	}
	dest[i] = 0;
	return (dest);
}

#ifdef TEST

int	main(void)
{
	return (0);
}

#endif