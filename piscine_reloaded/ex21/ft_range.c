/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 13:01:03 by juhong            #+#    #+#             */
/*   Updated: 2025/03/29 13:08:03 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*temp;

	if (max - min <= 0)
		return (NULL);
	temp = (int *)malloc(sizeof(int) * (max - min));
	i = min;
	while (i < max)
	{
		temp[i - min] = i;
		i++;
	}
	return (temp);
}
