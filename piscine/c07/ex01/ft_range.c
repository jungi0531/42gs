/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:20:04 by juhong            #+#    #+#             */
/*   Updated: 2025/02/04 20:22:32 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*array;

	if (min >= max)
		return (NULL);
	array = (int *)malloc(sizeof(int) * (max - min));
	if (!array)
		return (NULL);
	i = min;
	while (i < max)
	{
		array[i - min] = i;
		i++;
	}
	return (array);
}

#ifdef TEST

int	main(void)
{
	return (0);
}

#endif
